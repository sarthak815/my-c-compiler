#ifndef LEXER_HPP
#define LEXER_HPP

#include <regex>
#include <vector>
#include <string>

class Lexer {
public:
    struct Token {
        std::string type;
        std::string value;
        size_t position;
    };
    
    // Constructor/Destructor
    Lexer() = default;
    ~Lexer() = default;
    
    // Public interface
    void addRule(const std::string& name, const std::string& pattern, int priority = 0);
    std::vector<Token> tokenize(const std::string& input);
    
private:
    struct Rule {
        std::string name;
        std::regex pattern;
        int priority;
    };
    
    std::vector<Rule> rules;
};

#endif // LEXER_HPP
