#include <iostream>
#include <fstream>
#include <string>
#include <regex>

std::regex REGEX_ALL_NUMERIC_VALUE(R"(([-+]?\d*\.?\d+([eE][-+]?\d+)?))");

void ParseFileLineByLine(std::ifstream& file) {
	std::string buff;
	while (!file.eof()) {
		file >> buff;
		if (regex_match(buff, REGEX_ALL_NUMERIC_VALUE)) {
			std::cout << buff << std::endl;
		}
	}
}

int main(int argc, char* argv[]) {

	//if (argc <= 1) {
	//	std::cout << "Program required one argument: path to input file contains numbers" << std::endl;
	//	return 0;
	//}

	//std::string file_input_path = argv[1];

	std::string file_input_path = R"(C:\Users\Admin\source\repos\Ryabova_8\input.txt)";

	std::ifstream file_input(file_input_path);

	if (!file_input.is_open())
	{
		std::cout << "File " << file_input_path << " is not found" << std::endl;
		return 0;
	}
	else
		std::cout << "File " << file_input_path << " is read succesfully" << std::endl;

	ParseFileLineByLine(file_input);

	file_input.close();
}

