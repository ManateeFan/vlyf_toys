#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/* 
	����stream��ͷ�ո񣬲�ƥ��stream��ǰ׺�Ƿ�Ϊtext
	ƥ��ɹ�����true������streamƫ��text����
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
	ƥ��stream��ͷ�Ƿ�Ϊ���������ɹ�����true��
	�������������أ�����streamƫ�Ƶ���������
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
		Result.error = "������Ҫ����";
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
						Result.error = "����";
						Result.start = RightRead;
					}
					Result.result = left.result / right.result;
					break;
				default:
					Result.error = "δ֪����";
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
				Result.error = "�˴�ȱ��������";
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
	cout << "����һ�����ʽ��" << endl;
	cin >> Buffer;
	{
		char* stream = Buffer;
		Expression Result = GetExpression(stream);
		if (!Result.error.empty())
		{
			cout << "��������" << endl;
			cout << "λ�ã�" << Result.start << endl;
			cout << "��Ϣ��" << Result.error << endl;
		}
		else
		{
			cout << "�����" << Result.result << endl;
		}
	}
	system("PAUSE");
	return 0;
}