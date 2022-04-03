

#include <iostream>
#include <fstream>
#include <string>
#include "Vector3D.h"


int main(int argc, char* argv[]) {
	
	//if (argc <= 2) {
	//	std::cout << "Number of arguments is not correct. Program takes exact TWO arguments:" << std::endl
	//		<< "1 - path to input file" << std::endl
	//		<< "2 - path to output file (if it's not existed, program will create it)" << std::endl;
	//	return 0;
	//}

	//std::string file_input_path = argv[1];
	//std::string file_output_path = argv[2];
	std::string file_input_path = R"(C:\Users\Admin\source\repos\Ryabova_5_1\input.txt)";
	std::string file_output_path = R"(C:\Users\Admin\source\repos\Ryabova_5_1\output.txt)";

	std::ifstream file_input(file_input_path);

	if (!file_input.is_open())
	{
		std::cout << "File " << file_input_path << " is not found" << std::endl;
		return 0;
	}
	else
		std::cout << "File " << file_input_path << " is read succesfully" << std::endl;

	std::ofstream file_output(file_output_path);
	std::cout << "File " << file_output_path << " is opened for write succesfully" << std::endl;

	int x, y, z;
	try {
		file_input >> x >> y >> z;
	}
	catch(char* e)
	{
		std::cout << "Exception caught: " << e << ". Your input file has incorrect syntaxis" << std::endl;
		return 0;
	}

	Vector3D first_operand = Vector3D(x, y, z);

	std::string operator_symbol;
	try {
		file_input >> operator_symbol;
	}
	catch (char* e)
	{
		std::cout << "Exception caught: " << e << ". Your input file has incorrect syntaxis" << std::endl;
		return 0;
	}

	file_input >> x;
	Vector3D second_operand_vector = Vector3D();
	int second_operand_scalar = 0;
	bool is_second_oper_vect = false;

	try {
		if (file_input >> y >> z) {
			second_operand_vector = Vector3D(x, y, z);
			is_second_oper_vect = true;
		}
		else {
			second_operand_scalar = x;
		}
	}
	catch (char* e)
	{
		std::cout << "Exception caught: " << e << ". Your input file has incorrect syntaxis" << std::endl;
		return 0;
	}

	Vector3D result = Vector3D();

	if (operator_symbol == "*") {
		result = is_second_oper_vect ? first_operand * second_operand_vector : first_operand * second_operand_scalar;
	}
	else if (operator_symbol == "+") {
		result = is_second_oper_vect ? first_operand + second_operand_vector : first_operand + second_operand_scalar;
	}
	else if (operator_symbol == "-") {
		result = is_second_oper_vect ? first_operand - second_operand_vector : first_operand - second_operand_scalar;
	}
	else
	{
		std::cout << "Your input file has incorrect syntaxis" << std::endl;
		return 0;
	}

	file_output << "Computing " << first_operand << " " << operator_symbol << " ";

	if (is_second_oper_vect) {
		file_output << second_operand_vector;
	}
	else {
		file_output << second_operand_scalar;
	}

	file_output << " = " << result << std::endl;

	file_input.close();
	file_output.close();

	// Some tests:
	/*Vector3D example1 = Vector3D();
	Vector3D example2 = Vector3D(5, 6, 23);
	Vector3D example3 = Vector3D(1, 2, 3);


	std::cout << "||" << example1 << "|| = " << example1.norm() << std::endl;
	std::cout << "||" << example2 << "|| = " << example2.norm() << std::endl;
	std::cout << example1 << " + " << example2 << " = " << example1 + example2 << std::endl;
	std::cout << example1 << " - " << example2 << " = " << example1 - example2 << std::endl;
	std::cout << example1 << " + " << 10 << " = " << example1 + 10 << std::endl;
	std::cout << example2 << " * " << 10 << " = " << example2 * 10 << std::endl;
	std::cout << 10 << " * " << example2 << " = " << 10 * example2 << std::endl;
	std::cout << example3 << " * " << example2 << " = " << example3 * example2 << std::endl;*/

}