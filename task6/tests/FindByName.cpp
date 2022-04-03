#include <cassert>
#include "LinkedList.h"
Data data_arr[4] = { {4, "Susie"},
	{10, "Andrew"},
	{40, "Andrew"},
	{54, "Marina"},
};

List list = List(data_arr, 4);


void FindFirstElem_test() {

	Node *pointer = list.FindByName("Susie");

	assert(pointer->data.name == "Susie" && pointer ->data.value == 4);
}

void FindLastElem_test() {

	Node *pointer =  list.FindByName("Marina");

	assert(pointer->data.name == "Marina" && pointer->data.value == 54);

}

void FindNonExistentElem_test() {
	Node* pointer = list.FindByName("Gayorgy");
	assert(pointer == NULL);
}

void FindRepeatedElem_test() {
	Node* pointer = list.FindByName("Andrew");
	assert(pointer->data == Data(10, "Andrew"));
}

int main() {
	FindFirstElem_test();
	FindLastElem_test();
	FindNonExistentElem_test();
	FindRepeatedElem_test();
	return 0;
}