#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace vlyflexer
{
    enum class TokenType
    {
        INT,
        STRING,
        ID,
        REAL,
        OPERATOR,  // + - * / %
        COMMA,     // ,
        SPACE      // \t \n
    };

    class Token
    {
      public:
        TokenType   Type;
        std::string Value;

      public:
        using List = std::vector<Token>;
        Token(TokenType type, std::string const& value)
            : Type(type), Value(value)
        {
        }
    };

    enum class Stata
    {
        ZERO,
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        UNKNOWN
    };

    class Lexer
    {
      private:
        using TokenList = Token::List;
        std::string   FileName;
        std::ifstream Input;
        std::string   CurString;
        char          CurChar;
        TokenList     List;
        Stata         stata;

      public:
        Lexer(std::string const& File);
        void print()
        {
            for (int i = 0; i < List.size(); i++)
                std::cout << static_cast<int>(List[i].Type) << ": " << List[i].Value << std::endl;
        }
        // Token LexerInt();
        // Token LexerReal();
        // Token LexerOp();
        // Token LexerID();
        void MakeToken(TokenType type, std::string const& value);
        bool IsDigit(char Char)
        {
            return '0' <= Char && Char <= '9';
        }

        bool IsLetter(char Char)
        {
            return 'a' <= Char && Char <= 'z' || 'A' <= Char & Char <= 'Z';
        }

        bool IsOp(char Char)
        {
            return Char == '+' || Char == '-' || Char == '*' || Char == '/' ||
                   Char == '<' || Char == '>' || Char == '=' || Char == '(' ||
                   Char == ')';
        }
        void PreProcess()
        {
            while (CurChar == ' ') {
                Input.get(CurChar);
            }
            Input.putback(CurChar);
        }
    };
}  // namespace vlyflexer
