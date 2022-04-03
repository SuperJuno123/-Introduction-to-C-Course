#include <cassert>
#include "LinkedList.h"


void DeleteFirstElem_test() {

	Data original_data_arr[2] = { {4, "Susie"},
				{10, "Andrew"}
	};
	List list = List(original_data_arr, 2);

	bool result = list.DeleteByName("Susie");

	List estimated_list = List(original_data_arr[1]);

	assert(list == estimated_list);
	assert(result == true);
}

void DeleteLastElem_test() {

	Data original_data_arr[2] = { {4, "Susie"},
				{10, "Andrew"}
	};
	List list = List(original_data_arr, 2);

	list.DeleteByName("Andrew");

	List estimated_list = List(original_data_arr[0]);

	assert(list == estimated_list);
}

void DeleteSeveralElems_test() {
	Data original_data_arr[5] = { {4, "Susie"},
			{10, "Andrew"},
			{40, "Iwan"},
			{47, "Sasha"},
			{54, "Marina"},
	};
	List list = List(original_data_arr, 5);

	list.DeleteByName("Iwan");
	list.DeleteByName("Andrew");

	Data new_data_arr[3] = { original_data_arr[0],
	original_data_arr[3],
	original_data_arr[4] };

	List estimated_list = List(new_data_arr, 3);

	assert(list == estimated_list);
}

void DeleteRepeatedElem_test() {
	Data original_data_arr[2] = { {4, "Susie"},
				{40, "Susie"},
	};

	List list = List(original_data_arr, 2);

	list.DeleteByName("Susie");

	List estimated_list = List(Data(40, "Susie"));

	assert(list == estimated_list);


}

void DeleteNonExistentElem_test() {
	Data original_data_arr[2] = { {4, "Susie"},
					{10, "Andrew"},
	};

	List list = List(original_data_arr, 2);

	bool result = list.DeleteByName("Gayorgy");

	List estimated_list = List(original_data_arr, 2);

	assert(list == estimated_list);
	assert(result == false);


}

int main() {
	DeleteFirstElem_test();
	DeleteLastElem_test();
	DeleteSeveralElems_test();
	DeleteRepeatedElem_test();
	DeleteNonExistentElem_test();
	return 0;
}