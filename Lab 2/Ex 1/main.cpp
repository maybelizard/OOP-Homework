#include <iostream>
#include "NumberList.h"

int main() {
	NumberList list;
	list.Init();
	list.Add(9);
	list.Add(23);
	list.Add(34);
	list.Print();
	for (int i = 29; i >= 20; i--)
		list.Add(i);
	list.Print();
	list.Sort();
	list.Print();
	return 0;
}