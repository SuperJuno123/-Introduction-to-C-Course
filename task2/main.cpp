
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

int main() {

	int N;
	int buffer_size = 10000;

	std::cout << "Hello! Please type size of array:\n";

	while (!(std::cin >> N))
	{
		std::cout << "Try again\n";
		std::cin.clear();
		std::cin.ignore(buffer_size, '\n');
	}

	float *randArray1 = new float[N];
	float* randArray2 = new float[N];
	float* result = new float[N];

	double average = 0;
	double max = -SIZE_MAX;
	double min = SIZE_MAX;

	int column_width = 8;

	std::cout << std::setw(column_width) << "Array1" << "|" << std::setw(column_width) << "Array2" << "|" << std::setw(column_width) << "Result" << std::endl;

	for (int i = 0; i < N; i++) {
		randArray1[i] = (double)rand() / 10;
		randArray2[i] = (double)rand() / 10;
		result[i] = randArray1[i] + randArray2[i];
		average += result[i];
		if (result[i] > max){
			max = result[i];
		}
		else if (result[i] < min){
			min = result[i];
		}
		std::cout << std::setw(column_width) << randArray1[i] << "|" << std::setw(column_width) << randArray2[i] << "|" << std::setw(column_width) << result[i] << std::endl;
	}
	average /= N;

	std::cout << "Max element of result array is: " << max << ", min element is " << min << ", average: " << average;
}


