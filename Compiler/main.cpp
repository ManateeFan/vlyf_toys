#include "lexer.h"
#include <iostream>

using namespace std;
using namespace vlyflexer;
int main()
{
    Lexer lexer("123.txt");
    lexer.print();
    return 0;
}