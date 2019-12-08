#include "lexer.h"
#include <stdexcept>

namespace vlyflexer
{
    Lexer::Lexer(std::string const& File)
        : FileName(File), Input(std::ifstream(File)), stata(Stata::ZERO)
    {
        while (!Input.eof())
        {
            
            switch (stata)
            {
                case Stata::ZERO:

                    Input.get(CurChar);
                    if (IsDigit(CurChar))
                    {
                        CurString += CurChar;
                        stata = Stata::ONE;
                    }
                    else if (IsOp(CurChar))
                    {
                        CurString = CurChar;
                        MakeToken(TokenType::OPERATOR, CurString);
                        CurString.clear();
                        stata = Stata::ZERO;
                    }
                    else if (IsLetter(CurChar))
                    {
                        CurString += CurChar;
                        stata = Stata::FOUR;
                    }
                    else if (CurChar == '\"')
                    {
                        CurString += CurChar;
                        stata = Stata::FIVE;
                    }
                    else if (CurChar == ' ' || CurChar == '\t')
                    {
                        stata = Stata::ZERO;
                    }
                    else
                    {
                        stata = Stata::UNKNOWN;
                    }
                    break;
                case Stata::ONE:
                    Input.get(CurChar);
                    if (IsDigit(CurChar))
                    {
                        CurString += CurChar;
                        stata = Stata::ONE;
                    }
                    else if (CurChar == '.')
                    {
                        CurString += CurChar;
                        stata = Stata::TWO;
                    }
                    else
                    {
                        Input.putback(CurChar);
                        MakeToken(TokenType::INT, CurString);
                        CurString.clear();
                        stata = Stata::ZERO;
                    }
                    break;
                case Stata::TWO:
                    Input.get(CurChar);
                    if (IsDigit(CurChar))
                    {
                        CurString += CurChar;
                        stata = Stata::TWO;
                    }
                    else
                    {
                        Input.putback(CurChar);
                        MakeToken(TokenType::REAL, CurString);
                        CurString.clear();
                        stata = Stata::ZERO;
                    }
                    break;
                case Stata::FOUR:
                    Input.get(CurChar);
                    if (IsDigit(CurChar) || IsLetter(CurChar))
                    {
                        CurString += CurChar;
                        stata = Stata::FOUR;
                    }
                    else
                    {
                        Input.putback(CurChar);
                        MakeToken(TokenType::ID, CurString);
                        CurString.clear();
                        stata = Stata::ZERO;
                    }
                    break;
                case Stata::FIVE:
                    Input.get(CurChar);
                    if (CurChar == '\\')
                    {
                        CurString += CurChar;
                        stata = Stata::SIX;
                    }
                    else if (CurChar == '\"')
                    {
                        CurString += CurChar;
                        MakeToken(TokenType::STRING, CurString);
                        CurString.clear();
                        stata = Stata::ZERO;
                    }
                    else
                    {
                        CurString += CurChar;
                        stata = Stata::FIVE;
                    }
                    break;
                case Stata::SIX:
                    Input.get(CurChar);
                    if (CurChar == 'n' || CurChar == '\\' || CurChar == '\"')
                    {
                        CurString += CurChar;
                        stata = Stata::FIVE;
                    }
                    else
                    {
                        CurString.clear();
                        stata = Stata::UNKNOWN;
                    }
                    break;
                case Stata::UNKNOWN:
                    /*throw std::exception("Error");*/
                    return;
                    break;
            }
        }
    }

    void Lexer::MakeToken(TokenType type, std::string const& value)
    {
        List.push_back(Token(type, value));
    }

}  // namespace vlyflexer
