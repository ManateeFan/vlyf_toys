#pragma once
#include <iostream>
using namespace std;

class LinesCounter
{
	string fileName;
	int lines;
	bool IsBlank(const string& buff);
	bool IsCommentary(const string& buff);
public:
	LinesCounter(const string& file) :fileName(file), lines(0) 
	{
		Counter(fileName);
	}
	void Counter(const string& filename);
	int GetLines() const { return lines; }
};

