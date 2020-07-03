#include <iostream>
#include "LinkedList.hpp"
int main()
{
	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(0, 14);
	// list.clear();
	list.add(6);
	list.display();

	return 0;
}
