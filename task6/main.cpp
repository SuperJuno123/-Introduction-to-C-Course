
#include <iostream>
#include <fstream>
#include <sstream> // ?
#include <string>
#include <iomanip>
#include "LinkedList.h"
#include <vector>

/// <summary>
/// By https://stackoverflow.com/a/46931770
/// </summary>
/// <param name="s"></param>
/// <param name="delim"></param>
/// <returns></returns>
std::vector<std::string> Split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

/// <summary>
/// By https://stackoverflow.com/a/4654718
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool IsNumber(const std::string& s)
{
	if (s.empty())
		return false;

	std::string::const_iterator iterator = s.begin();
	while (iterator != s.end() && std::isdigit(*iterator))
		++iterator;
	return iterator == s.end();
}

List ParseListFile(std::ifstream& file) {
	List list = List();
	std::string value_buff;
	std::string name_buff;

	while (!file.eof()) {
		file >> value_buff >> name_buff;
		list.AddByValueOrder(Data(std::stoi(value_buff), name_buff));
	}

	return list;
}

void ErrorParsingHandler_InvalidCommand(std::string line) {
	std::cout << "Line \"" << line << "\" was ignored because command is not valid or cannot take that number of arguments" << std::endl;
}

void ErrorParsingHandler_InvalidArgument(std::string line) {
	std::cout << "Line \"" << line << "\" was ignored because argument value(s) is not valid" << std::endl;
}

void ErrorParsingHandler_InvalidNumberOfArgument(std::string line) {
	std::cout << "Line \"" << line << "\" was ignored because there are too many arguments" << std::endl;
}

void SuccesfulParsingHandler(std::string line) {
	std::cout << "Line \"" << line << "\" was executed succesfully" << std::endl;
}

void ParseCommandFile(std::ifstream& file, List& list) {
	std::string current_line;
	std::vector<std::string> parts_of_cur_line;
	int index_of_line = 0;
	char delimiter = ' ';
	int margin_width = 4;
	std::cout << std::setw(margin_width + 2) << " " << "Start executing commands" << std::endl;

	while (!file.eof()) {
		getline(file, current_line);
		if (current_line == "")
			continue;

		std::cout << std::setw(margin_width) << index_of_line << ": ";

		parts_of_cur_line = Split(current_line, delimiter);
		std::string command = parts_of_cur_line[0];

		if (parts_of_cur_line.size() == 3) {

			if (command == "add") {
				//Estimated command format:	add value name

				int value;

				if (IsNumber(parts_of_cur_line[1]))
					value = std::stoi(parts_of_cur_line[1]);
				else {
					ErrorParsingHandler_InvalidArgument(current_line);
					continue;
				}

				std::string name = parts_of_cur_line[2];

				list.AddByValueOrder(value, name);
				SuccesfulParsingHandler(current_line);
			}
			else
				ErrorParsingHandler_InvalidCommand(current_line);
		}
		else if (parts_of_cur_line.size() == 2) {
			if (command == "remove_value") {
				int value;
				if (IsNumber(parts_of_cur_line[1]))
					value = std::stoi(parts_of_cur_line[1]);
				else {
					ErrorParsingHandler_InvalidArgument(current_line);
					continue;
				}
				if (list.DeleteByValue(value))
					std::cout << "Element with value " << value << " was deleted succesfully" << std::endl;
				else
					std::cout << "Element with value " << value << " was not deleted because it wasn't in list" << std::endl;
				SuccesfulParsingHandler(current_line);
			}
			else if (command == "remove_name") {
				std::string name = parts_of_cur_line[1];
				if (list.DeleteByName(name))
					std::cout << "Element with name " << name << " was deleted succesfully" << std::endl;
				else
					std::cout << "Element with name " << name << " was not deleted because it wasn't in list" << std::endl;
				SuccesfulParsingHandler(current_line);
			}
			else if (command == "search_value") {
				int value;
				if (IsNumber(parts_of_cur_line[1]))
					value = std::stoi(parts_of_cur_line[1]);
				else {
					ErrorParsingHandler_InvalidArgument(current_line);
					continue;
				}
				Node* p = list.FindByValue(value);
				if (p != NULL) {
					std::cout << "Found element by value \"" << value << "\": [" << p->data.value << ", " << p->data.name << "] " << std::endl;
				}
				else
					std::cout << "Element with value " << value << " is not found in the list" << std::endl;
				SuccesfulParsingHandler(current_line);
			}
			else if (command == "search_name") {
				std::string name = parts_of_cur_line[1];
				Node* p = list.FindByName(name);
				if (p != NULL) {
					std::cout << "Found element by name \"" << name << "\": [" << p->data.value << ", " << p->data.name << "] " << std::endl;
				}
				else
					std::cout << "Element with name " << name << " is not found in the list" << std::endl;
				SuccesfulParsingHandler(current_line);
			}
			else
				ErrorParsingHandler_InvalidCommand(current_line);
		}
		else if (parts_of_cur_line.size() == 1) {
			if (command == "count") {
				std::cout << "List count: " << list.Count() << std::endl;
				SuccesfulParsingHandler(current_line);
			}
			else if (command == "print") {
				list.Print();
				SuccesfulParsingHandler(current_line);
			}
			else
				ErrorParsingHandler_InvalidCommand(current_line);
		}
		else
			ErrorParsingHandler_InvalidNumberOfArgument(current_line);
		index_of_line++;
	}
}




int main(int argc, char* argv[]) {

	if (argc <= 2) {
		std::cout << "Number of arguments is not correct. Program takes exact TWO arguments:" << std::endl
			<< "1 - path to input file with elements of list (can be empty)" << std::endl
			<< "2 - path to input file with commands (can be empty)" << std::endl;
		return 0;
	}


	std::string file_input_1_elems_path = argv[1];
	std::string file_input_2_commands_path = argv[2];
	//std::string file_input_1_elems_path = R"(C:\Users\Admin\source\repos\Ryabova_6\list.txt)";
	//std::string file_input_2_commands_path = R"(C:\Users\Admin\source\repos\Ryabova_6\commands.txt)";

	std::ifstream file_input_1_elems(file_input_1_elems_path);

	if (!file_input_1_elems.is_open())
	{
		std::cout << "File contains elements of list is not found. File " << file_input_1_elems_path << " is not existed " << std::endl;
		return 0;
	}
	else
		std::cout << "File contains elements of list (" << file_input_1_elems_path << ") is read succesfully" << std::endl;

	std::ifstream file_input_2_commands(file_input_2_commands_path);

	if (!file_input_2_commands.is_open())
	{
		std::cout << "File contains commands is not found. File " << file_input_2_commands_path << " is not existed " << std::endl;
		return 0;
	}
	else
		std::cout << "File contains commands (" << file_input_2_commands_path << ") is read succesfully" << std::endl;

	List list = ParseListFile(file_input_1_elems);
	file_input_1_elems.close();
	std::cout << "List has been parsed from file: " << std::endl;
	list.Print();

	ParseCommandFile(file_input_2_commands, list);
	std::cout << "All commands was parsed. List with " << list.Count() << " elements afrer execution of all commands: " << std::endl;
	list.Print();

}