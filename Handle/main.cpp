#include <iostream>
#include "Handle.h"
using namespace std;

int main()
{
	Handle h1(1, 2);
	Handle h2(3, 4);
	Handle h3(h1);
	cout << "h1: " << h1.x() << " " << h1.y() << endl;
	cout << "h2: " << h2.x() << " " << h2.y() << endl;
	cout << "h3: " << h3.x() << " " << h3.y() << endl;
	return 0;
}