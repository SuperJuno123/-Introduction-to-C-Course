
#include <iostream>
#include <fstream>
#include <string>
#include <string.h> 
#include <stdio.h>

int main(int argc, char* argv[]) {

	//std::string path = argv[1];
	//int min_protein_length = std::stoi(argv[2]);

	std::string path = R"(C:\Users\Admin\source\repos\Ryabova_4\SARSCoV2seq.txt)";
	int min_protein_length = 18;

	const char ATG[3 + 1] = "ATG";

	const char* stop_codons[3] = { "TAA", "TAG", "TGA" };

	std::ifstream f_input(path);

	if (!f_input.is_open())
	{
		std::cout << "File " << path << " is not found" << std::endl;
		return 0;
	}
	else
		std::cout << "File " << path << " is read succesfully" << std::endl;

	int codon_size = 3;
	char* buff_codon = new char[codon_size + 1];

	int indexer = 0;
	bool ATG_found_flag = false;
	int index_of_ATG_start = 0;
	int number_of_proteins = 0;
	int step = 1;

	std::cout << "Seeking all proteins contains at least " << min_protein_length << " nucleotides" << std::endl;

	while (!f_input.eof()) {
		f_input.seekg(indexer, std::ios::beg);
		f_input.get(buff_codon, codon_size + 1);

		if (!ATG_found_flag) {
			if (strcmp(buff_codon, ATG) == 0) {
				ATG_found_flag = true;
				index_of_ATG_start = indexer;
				step = 3;
			}
		}
		else {
			// "TAA", "TAG", "TGA"
			if (strcmp(buff_codon, stop_codons[0]) == 0 || 
				strcmp(buff_codon, stop_codons[1]) == 0 || 
				strcmp(buff_codon, stop_codons[2]) == 0) {
				int length_of_protein = indexer - (index_of_ATG_start - 1) + 2;
				if (!(length_of_protein < min_protein_length))
				{	
					char* buffer = new char[length_of_protein + 1];
					f_input.seekg(index_of_ATG_start, std::ios::beg);
					f_input.get(buffer, length_of_protein + 1);
					std::cout << "Protein " << number_of_proteins + 1 << ", length " << length_of_protein << ", start position: "
						<< index_of_ATG_start << ", end position: " << index_of_ATG_start + length_of_protein << std::endl;

					delete[] buffer;
					number_of_proteins += 1;					
				}
				indexer = index_of_ATG_start;
				step = 1;
				ATG_found_flag = false;
			}
		}
		indexer += step;
	}

	delete[] buff_codon;

	std::cout << "Result: for minimum protein length: " << min_protein_length << " was found " <<
		number_of_proteins << " proteins" << std::endl;
}


