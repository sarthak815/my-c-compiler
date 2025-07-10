#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <iostream>

enum class TokenType {
    // Literals
    INTEGER,
    FLOAT,
    STRING,
    IDENTIFIER,
    
    // Operators
    PLUS,
    PLUS_PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    
    // Keywords
    IF,
    ELSE,
    WHILE,
    FUNCTION,
    
    // Special
    EOF_TOKEN,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
    size_t line;
    size_t column;
    
    Token(TokenType t, const std::string& v, size_t l, size_t c)
        : type(t), value(v), line(l), column(c) {}
};

// Helper function to convert TokenType to string
inline std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::INTEGER: return "INTEGER";
        case TokenType::FLOAT: return "FLOAT";
        case TokenType::STRING: return "STRING";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::PLUS: return "PLUS";
        case TokenType::PLUS_PLUS: return "PLUS_PLUS";
        // ... add more cases
        default: return "UNKNOWN";
    }
}

// Stream operator for easy printing
inline std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << "[" << tokenTypeToString(token.type) << ": '" 
       << token.value << "' at " << token.line << ":" << token.column << "]";
    return os;
}

#endif // TOKEN_HPP
