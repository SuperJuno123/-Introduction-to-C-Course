#include <cassert>
#include "LinkedList.h"

void Count_test() {
	Data data_arr[4] = { {4, "Susie"},
		{10, "Andrew"},
		{40, "Iwan"},
		{54, "Marina"},
	};
	List list = List(data_arr, 4);

	assert(list.Count() == 4);

}

int main() {
	Count_test();
	return 0;
}