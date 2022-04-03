

#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

int main()
{
    std::cout << "Hello, dear user. Please say me your name:\n";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Nice to meet you, " << name << "!\nCan you please tell me how old are you?\n";

    int age;

    while ((std::cout << "Please type integer number\n") && !(std::cin >> age) || age < 0 || age > 122)
    {
        std::cout << "Sir or madame it's cannot be your age!\n";
        std::cin.clear(); // очищает флаг ошибки на cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // переходит к следующей новой строке 
        // (чтобы игнорировать что-либо еще в той же строке, что и не-число, чтобы это не вызвало еще один сбой синтаксического анализа).
        //Он будет пропускать только до numeric_limits<std::streamsize>::max() символов
    }


    auto now = std::chrono::system_clock::now();
    std::time_t cur_point_of_time = std::chrono::system_clock::to_time_t(now);
    struct tm* time_structure = std::localtime(&cur_point_of_time); //Указатель на структуру time structure

    // pointer->field - аналог (*pointer).field

    std::cout << "I guess you was born in: " << 1900 + time_structure->tm_year - age << ", am I right?\n";
    std::string answer;

    while (!(std::cin >> answer) || !(answer == "yes" || answer == "no")) {
        std::cout << "Sorry, I can't understand you\n";
    }
    if (answer == "yes")
    {
        std::cout << "Hooray!";
    }
    else
    {
        std::cout << 1900 + time_structure->tm_year - age - 1 << " then";
    }
}

