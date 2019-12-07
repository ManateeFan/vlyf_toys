#include <iostream>
#include <string>
#include <fstream>
#include <vector>



    using namespace std;
    enum class TokenType
    {
        INT,
        STRING,
        ID,
        REAL,
        OPERATOR, // + - * / %
        COMMA,    // ,
        SPACE     // \t \n
    };

    class Token
    {
    public:
        using List = vector<Token>;
        TokenType Type;
        string Value;
    };

    class Lexer
    {
        using List = Token::List;
    private:
        string FileName;
        ifstream Input;

        string CurString;
        List TokenList;

    public:
        Lexer(string const& file) : FileName(file), Input(ifstream(FileName)) 
        {
            BeginLexer();
        }

        void print()
        {
            for (auto item : TokenList)
            {
                cout << static_cast<int>(item.Type) << "  " << item.Value << endl;
            }
        }
        void PreProcess()
        {
            char ch;
            while (isspace(Input.peek()))
            {
                Input.get(ch);
            }
        }

        Token MakeToken(TokenType type, string const& value)
        {
            Token token;
            token.Type = type;
            token.Value = value;
            return token;
        }

        void BeginLexer()
        {
            enum class Stata
            {
                ZERO, // begin
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINGHT,
                TEN,

                FALSE
            };
            Stata stata = Stata::ZERO;
            char ch;
            while (!Input.eof())
            {
                PreProcess();
                Input.get(ch);
                switch (stata)
                {
                case Stata::ZERO:
                    if ('0' <= ch&& ch <= '9')
                    {
                        stata = Stata::ONE;
                        CurString = ch;
                    }
                    else if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z')
                    {
                        stata = Stata::TWO;
                        CurString = ch;
                    }
                    else if (ch == '+')
                    {
                        stata = Stata::THREE;
                        CurString = ch;
                    }
                    else if (ch == '-')
                    {
                        stata = Stata::FOUR;
                        CurString = ch;
                    }
                    else if (ch == '*')
                    {
                        stata = Stata::FIVE;
                        CurString = ch;
                    }
                    else if (ch == '(')
                    {
                        stata = Stata::SIX;
                        CurString = ch;
                    }
                    else if (ch == ')')
                    {
                        stata = Stata::SEVEN;
                        CurString = ch;
                    }
                    else
                    {
                        stata = Stata::FALSE;
                    }
                    break;
                case Stata::ONE:
                    Input.putback(ch);
                    Input.get(ch);
                    if ('0' <= ch && ch <= '9')
                    {
                        stata = Stata::ONE;
                        CurString += ch;
                    }
                    else if (ch == '.')
                    {
                        stata = Stata::EIGHT;
                        CurString += ch;
                    }
                    else
                    {
                        TokenList.push_back(MakeToken(TokenType::INT, CurString));
                        Input.putback(ch);
                        stata = Stata::FALSE;
                    }
                    break;
                case Stata::TWO:
                    Input.putback(ch);
                    Input.get(ch);
                    if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z')
                    {
                        stata = Stata::TWO;
                        CurString += ch;
                    }
                    else if ('0' <= ch && ch <= '9')
                    {
                        stata = Stata::NINGHT;
                        CurString += ch;
                    }
                    else
                    {
                        TokenList.push_back(MakeToken(TokenType::ID, CurString));
                        Input.putback(ch);
                        stata = Stata::FALSE;
                    }
                    break;
                case Stata::THREE:
                    TokenList.push_back(MakeToken(TokenType::OPERATOR, "+"));
                    break;
                case Stata::FOUR:
                    TokenList.push_back(MakeToken(TokenType::OPERATOR, "-"));
                    break;
                case Stata::FIVE:
                    TokenList.push_back(MakeToken(TokenType::OPERATOR, "/"));
                case Stata::SIX:
                    TokenList.push_back(MakeToken(TokenType::OPERATOR, "("));
                    break;
                case Stata::SEVEN:
                    TokenList.push_back(MakeToken(TokenType::OPERATOR, ")"));
                    break;
                default:
                    break;
                }
            }
        }
    };

int main()
{   
    Lexer lexer("123.text");

        return 0;
}