// program name: Lines Counter
// author: vlyf
// count the lines of your code in C or C++ without
// the commentaries and blank lines
// time: 2019/11/9

#include <iostream>
#include <fstream>
#include "LinesCounter.h"

inline
bool LinesCounter::IsBlank(const string& buff)
{
	for (auto& ch : buff)
	{
		if (ch - ' ' != 0)
			return false;
	}
	return true;
}

inline
bool LinesCounter::IsCommentary(const string& buff)
{
	if (buff.substr(0, 2) == "//" || buff.substr(0, 2) == "/*")
		return true;
	if (buff.length()>=2&&buff.substr(buff.length() - 2) == "*/")
		return true;
	return false;
}
inline
void LinesCounter::Counter(const string& fileName)
{
	char* buff = new char[100];
	ifstream is(fileName, std::ifstream::in);
	if (!is.is_open())
	{
		cerr << "Error openning file!";
		exit(1);
	}
	while (!is.eof())
	{
		is.getline(buff, 100);
		if (!IsBlank(buff) && !IsCommentary(buff))
			lines++;
	}
	delete[]buff;
}
int main()
{
	string fileName;
	cout << "输入文件名：" << endl;
	cin >> fileName;
	LinesCounter count(fileName);
	cout << "实际代码行数：" << count.GetLines() << endl;
	return 0;
}