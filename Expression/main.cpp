#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/* 
	过滤stream开头空格，并匹配stream的前缀是否为text
	匹配成功返回true，并将stream偏移text长度
*/
bool IsText(char*& stream, char const* text)
{
	size_t len = strlen(text);
	char* read = stream;
	while (*read == ' ')
		read++;
	if (strncmp(read, text, len) == 0)
	{
		stream = read + len;
		return true;
	}
	else
	{
		return false;
	}
}

/* 
	匹配stream开头是否为操作符，成功返回true，
	并将操作符返回，并将stream偏移到操作符后
*/

char IsOperator(char*& stream)
{
	if (IsText(stream, "+") || IsText(stream, "-") || IsText(stream, "*") || IsText(stream, "/"))
	{
		return stream[-1];
	}
	else
	{
		return 0;
	}
}

struct Expression
{
	int result;
	std::string error;
	char* start;
};

Expression GetNumber(char*& stream)
{
	Expression Result;
	Result.result = 0;
	Result.error = "";
	Result.start = nullptr;
	char* read = stream;
	bool gotNumber = false;
	while (*read == ' ')
		read++;
	while (true)
	{
		char c = *read;
		if ('0' <= c && c <= '9')
		{
			Result.result = Result.result * 10 + (c - '0');
			gotNumber = true;
			read++;
		}
		else
		{
			break;
		}
	}
	if (gotNumber)
	{
		stream = read;
	}
	else
	{
		Result.error = "这里需要数字";
		Result.start = read;
	}
	return Result;
}

Expression GetExpression(char*& stream)
{
	char* read = stream;
	Expression Result = GetNumber(read);
	if (Result.error != "")
	{
		if (IsText(read, "("))
		{
			Result.error = "";
			char Operator = 0;
			if ((Operator = IsOperator(read)) != 0)
			{
				Expression left = GetExpression(read);
				if (left.error!="") return left;
				char* RightRead = read;
				Expression right = GetExpression(read);
				if (right.error!="") return right;

				switch (Operator)
				{
				case '+':
					Result.result = left.result + right.result;
					break;
				case '-':
					Result.result = left.result + right.result;
					break;
				case '*':
					Result.result = left.result * right.result;
					break;
				case '/':
					if (right.result == 0)
					{
						Result.error = "除错";
						Result.start = RightRead;
					}
					Result.result = left.result / right.result;
					break;
				default:
					Result.error = "未知错误";
					Result.start = read;
					return Result;
				}
			}
			else
			{
				Result = GetExpression(read);
				if (Result.error!= "")
					return Result;
			}
			if (!IsText(read, ")"))
			{
				Result.error = "此处缺少右括号";
				Result.start = read;
			}
		}
	}
	if (Result.error == "")
	{
		stream = read;
	}
	return Result;
}

int main()
{
	char Buffer[1000];
	cout << "输入一个表达式：" << endl;
	cin >> Buffer;
	{
		char* stream = Buffer;
		Expression Result = GetExpression(stream);
		if (!Result.error.empty())
		{
			cout << "发生错误" << endl;
			cout << "位置：" << Result.start << endl;
			cout << "信息：" << Result.error << endl;
		}
		else
		{
			cout << "结果：" << Result.result << endl;
		}
	}
	system("PAUSE");
	return 0;
}