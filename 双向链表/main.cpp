#include "LinkedList.hpp"

int main()
{
	LinkedList<int> list;
	list.add(1);

	list.remove(0);
	list.display();

	return 0;
}
