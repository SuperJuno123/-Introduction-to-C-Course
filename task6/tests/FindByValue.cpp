#include <cassert>
#include "LinkedList.h"
Data data_arr[4] = { {4, "Susie"},
	{10, "Andrew"},
	{10, "Iwan"},
	{54, "Marina"},
};

List list = List(data_arr, 4);


void FindFirstElem_test() {

	Node* pointer = list.FindByValue(4);
	assert(pointer->data == Data(4, "Susie"));
}

void FindLastElem_test() {

	Node* pointer = list.FindByValue(54);
	assert(pointer->data == Data(54, "Marina"));

}

void FindNonExistentElem_test() {
	Node* pointer = list.FindByValue(999);
	assert(pointer == NULL);
}

void FindRepeatedElem_test() {
	Node* pointer = list.FindByValue(10);
	assert(pointer->data == Data(10, "Andrew"));
}

int main() {
	FindFirstElem_test();
	FindLastElem_test();
	FindNonExistentElem_test();
	FindRepeatedElem_test();
	return 0;
}