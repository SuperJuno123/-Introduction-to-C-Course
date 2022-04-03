#include <cassert>
#include "LinkedList.h"
// ���� �������� #include <LinkedList.h> � � ���� ���� ����((

void AddByOrder_test() {
	Data data_arr[4] = { {4, "Susie"},
		{10, "Andrew"},
		{40, "Iwan"},
		{54, "Marina"},
	};
	List estimated_list = List(data_arr, 4);

	List list;
	
	list.AddByValueOrder(Data(54, "Marina"));
	list.AddByValueOrder(Data(10, "Andrew"));
	list.AddByValueOrder(4, "Susie");
	list.AddByValueOrder(40, "Iwan");

	// ����������: �� � �������, ������������ �� ���������, � �������� ������ (��. ��������������� ��������� ==)
	assert(list == estimated_list);
}


int main() {
	AddByOrder_test();
	return 0;
}