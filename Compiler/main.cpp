#include "lexer.h"
#include <iostream>

using namespace std;
using namespace vlyflexer;
int main()
{
    string str = "int a = 5 int b = 10 int m = 0 ";
    wstring file(str.begin(), str.end());
    Lexer lexer(file);
    lexer.print();
    return 0;
}