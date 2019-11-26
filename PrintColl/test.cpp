#include <iostream>
#include "PrintColl.hpp"
#include <vector>

int main()
{
	std::vector<int> v(10, 1);
	printColl(v);
	return 0;
}