#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace vlyflexer
{
    using namespace std;
    enum class TokenType
    {
        Unknown,
        Number,
        Comment,
        Operator,
        Identifier,
        String
    };

    struct Token
    {
        using List          = vector<Token>;
        TokenType    type   = TokenType::Unknown;
        int          row    = -1;
        int          column = -1;
        std::wstring value;
        Token() = default;
        Token(int            r,
              int            c,
              TokenType      t,
              wchar_t const* begin,
              wchar_t const* end)
            : row(r), type(t), column(c),
              value(begin, end)  // Copies the sequence of characters in the
                                 // range [first,last), in the same order.
        {
            if (type == TokenType::String)
            {
                for (int i = 0; i < value.length(); i++)
                {
                    if (value[i] == '\\')
                    {
                        if (i + 1 < value.length())
                        {
                            switch (value[i + 1])
                            {
                                case '\\':
                                {
                                    //  将从索引i开始的2个字符换为1个'\'
                                    value.replace(i, 2, 1, '\\');
                                    break;
                                }
                                case 'n':
                                {
                                    value.replace(i, 2, 1, '\n');
                                    break;
                                }
                                case '\"':
                                {
                                    value.replace(i, 2, 1, '\"');
                                    break;
                                }
                                default:
                                {
                                    throw std::exception("Error escape");
                                    break;
                                }
                            }
                        }
                        else
                        {
                            throw std::exception("Error escape");
                        }
                    }
                }
            }
        }
    };

    enum class State
    {
        Start,
        Integer,
        Float,
        Comment,
        EndComment,
        Operator,
        Identifier,
        String,
        StringEnd,
        Escape
    };

    class Lexer
    {
      private:
        using TokenList = Token::List;
        struct ParsingState
        {
            State          state;
            int            row;
            int            column;
            wchar_t const* begin;
            wchar_t const* end;
        };
        TokenList List;

        void MakeToken(ParsingState const& state, TokenType type)
        {
            List.push_back(
                Token(state.row, state.column, type, state.begin, state.end));
        }

      public:
        Lexer(wstring const& Input)
        {
            ParsingState state{State::Start, 0, 0, Input.c_str(),
                               Input.c_str()};
            int          r = 1;
            int          c = 1;
            while (*state.end)
            {
                switch (state.state)
                {
                    case State::Start:
                        state.begin  = state.end;
                        state.row    = 1;
                        state.column = 1;
                        switch (*state.end)
                        {
                            case '+':
                            case '-':
                            case '*':
                            case '/':
                            case '=':
                            case '(':
                            case ')':
                            case '<':
                            case '>':
                            case '&':
                            case '^':
                            case '~':
                            {
                                state.end++;
                                MakeToken(state, TokenType::Operator);
                                state.end--;
                                break;
                            }
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                            case '8':
                            case '9':
                            {
                                state.state = State::Integer;
                                break;
                            }
                            case 'a':
                            case 'b':
                            case 'c':
                            case 'd':
                            case 'e':
                            case 'f':
                            case 'g':
                            case 'h':
                            case 'i':
                            case 'j':
                            case 'k':
                            case 'l':
                            case 'm':
                            case 'n':
                            case 'o':
                            case 'p':
                            case 'q':
                            case 'r':
                            case 's':
                            case 't':
                            case 'u':
                            case 'v':
                            case 'w':
                            case 'x':
                            case 'y':
                            case 'z':
                            case 'A':
                            case 'B':
                            case 'C':
                            case 'D':
                            case 'E':
                            case 'F':
                            case 'G':
                            case 'H':
                            case 'I':
                            case 'J':
                            case 'K':
                            case 'L':
                            case 'M':
                            case 'N':
                            case 'O':
                            case 'P':
                            case 'Q':
                            case 'R':
                            case 'S':
                            case 'T':
                            case 'U':
                            case 'V':
                            case 'W':
                            case 'X':
                            case 'Y':
                            case 'Z':
                            case '_':
                            {
                                state.state = State::Identifier;
                                break;
                            }
                            case '#':
                            {
                                state.begin++;
                                state.state = State::Comment;
                            }
                            case '\"':
                            {
                                state.begin++;
                                state.state = State::String;
                            }
                            case '\n':
                            {
                                state.row++;
                                state.column = 0;
                                break;
                            }
                            case ' ': break;

                            default: throw std::exception("Lexer error"); break;
                        }
                        break;
                    case State::Integer:
                    {
                        switch (*state.end)
                        {
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                            case '8':
                            case '9': 
                                if(!*(state.end+1))
                                    {
                                    ParsingState s = state;
                                        s.end++;
                                        state.state = State::Start;
                                        MakeToken(s, TokenType::Number);
                                    }
                                    break;
                            case '.': state.state = State::Float; break;
                            default:
                            {
                                state.state = State::Start;
                                MakeToken(state, TokenType::Number);
                                state.end--;
                                state.column--;
                                break;
                            }
                        }
                        break;
                    }
                    case State::Comment:
                    {
                        if (*state.end == '\n' || *state.end == '#')
                        {
                            state.state = State::Start;
                            if (*state.end == '\n')
                            {
                                state.row++;
                            }
                            state.column = 1;
                            MakeToken(state, TokenType::Comment);
                        }
                        break;
                    }
                    case State::Identifier:
                    {
                        switch (*state.end)
                        {
                            case 'a':
                            case 'b':
                            case 'c':
                            case 'd':
                            case 'e':
                            case 'f':
                            case 'g':
                            case 'h':
                            case 'i':
                            case 'j':
                            case 'k':
                            case 'l':
                            case 'm':
                            case 'n':
                            case 'o':
                            case 'p':
                            case 'q':
                            case 'r':
                            case 's':
                            case 't':
                            case 'u':
                            case 'v':
                            case 'w':
                            case 'x':
                            case 'y':
                            case 'z':
                            case 'A':
                            case 'B':
                            case 'C':
                            case 'D':
                            case 'E':
                            case 'F':
                            case 'G':
                            case 'H':
                            case 'I':
                            case 'J':
                            case 'K':
                            case 'L':
                            case 'M':
                            case 'N':
                            case 'O':
                            case 'P':
                            case 'Q':
                            case 'R':
                            case 'S':
                            case 'T':
                            case 'U':
                            case 'V':
                            case 'W':
                            case 'X':
                            case 'Y':
                            case 'Z':
                            case '_': break;

                            default:
                            {
                                state.state = State::Start;
                                MakeToken(state, TokenType::Identifier);
                                state.end--;
                                state.column--;
                                break;
                            }
                        }
                        break;
                    }
                    case State::String:
                    {
                        switch (*state.end)
                        {
                            case '\\': state.state = State::Escape; break;
                            case '"':
                            {
                                state.state = State::Start;
                                MakeToken(state, TokenType::String);
                                break;
                            }
                            case '\n':
                                throw std::exception("Parser error in string");
                                break;
                            default: break;
                        }
                    }
                    break;
                    case State::Float:
                    {
                        switch (*state.end)
                        {
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                            case '8':
                            case '9': break;

                            default:
                            {
                                MakeToken(state, TokenType::Number);
                                state.state = State::Start;
                                state.end--;
                                c--;
                                break;
                            }
                        }
                    }
                    break;
                    case State::Escape:
                    {
                        if (*state.end == 'n' || *state.end == '\\' ||
                            *state.end == '"')
                        {
                            break;
                        }
                        else
                        {
                            throw std::exception("Error in string escape");
                            break;
                        }
                    }
                    break;
                }
                state.end++;
                c++;
            }
        }

        void print()
        {
            for (auto item : List) {
                cout << "type: " << static_cast<int>(item.type) << "  value: ";
                wcout << item.value << endl;
            }
        }
    };
}  // namespace vlyflexer
