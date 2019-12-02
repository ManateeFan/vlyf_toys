#include <iostream>

using namespace std;

enum class Stata
{
	s0,
	s1,
	s2,
	s3,
	s4,
	s5,
	s6,
	s7,
	s8,
	s9,
	s10,
	se
};

void Fuck_abbbb(string const& str)
{
	Stata stata = Stata::s0;
	for (auto ch : str)
	{
		switch (stata)
		{
		case Stata::s0:
			if (ch == 'a') stata = Stata::s1;
			else stata = Stata::se;
			break;
		case Stata::s1:
			if (ch == 'b') stata = Stata::s1;
			else stata = Stata::se;
			break;
		case Stata::se:
			break;
		}
	}
	if (stata == Stata::s1)
		cout << "Success" << endl;
	else
		cout << "Fail" << endl;
}


void Fuck_new_while_not(string const& str)
{
	Stata stata = Stata::s0;
	for (auto ch : str)
	{
		switch (stata)
		{
		case Stata::s0:
			if (ch == 'n') stata = Stata::s1;
			else if (ch == 'w') stata = Stata::s6;
			else stata = Stata::se;
			break;
		case Stata::s1:
			if (ch == 'e') stata = Stata::s2;
			else if (ch == 'o') stata = Stata::s4;
			else stata = Stata::se;
			break;
		case Stata::s2:
			if (ch == 'w') stata = Stata::s3;
			else stata = Stata::se;
			break;
		case Stata::s3:
			break;
		case Stata::s4:
			if (ch == 't') stata = Stata::s5;
			else stata = Stata::se;
			break;
		case Stata::s5:
			break;
		case Stata::s6:
			if (ch == 'h') stata = Stata::s7;
			else stata = Stata::se;
			break;
		case Stata::s7:
			if (ch == 'i') stata = Stata::s8;
			else stata = Stata::se;
			break;
		case Stata::s8:
			if (ch == 'l') stata = Stata::s9;
			else stata = Stata::se;
			break;
		case Stata::s9:
			if (ch == 'e') stata = Stata::s10;
			else stata = Stata::se;
			break;
		case Stata::s10:
			break;
		case Stata::se:
			break;
		}
	}
	if (stata == Stata::s3)
	{
		cout << "Success: new" << endl;
	}
	else if (stata == Stata::s5)
	{
		cout << "Success: not" << endl;
	}
	else if (stata == Stata::s10)
	{
		cout << "Success: while" << endl;
	}
	else
	{
		cout << "Fail" << endl;
	}
}
int main()
{
	string str;
	cout << "match ab*: ";
	cin >> str;
	Fuck_abbbb(str);
	cout << "------------------" << endl;
	cout << "match new|while|not: ";
	cin >> str;
	Fuck_new_while_not(str);
	return 0;
}