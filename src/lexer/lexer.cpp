#include "lexer.hpp"
#include <iostream>
#include <stdexcept>
#include <climits>

void Lexer::addRule(const std::string& name, const std::string& pattern, int priority) {
    rules.push_back({name, std::regex("^" + pattern), priority});
}

std::vector<Lexer::Token> Lexer::tokenize(const std::string& input) {
    std::vector<Token> tokens;
    size_t pos = 0;
    
    while (pos < input.length()) {
        // Skip whitespace
        while (pos < input.length() && std::isspace(input[pos])) {
            pos++;
        }
        
        if (pos >= input.length()) break;
        
        // Find longest match
        std::string bestMatch;
        std::string bestType;
        int bestPriority = INT_MAX;
        
        std::string remaining = input.substr(pos);
        
        for (const auto& rule : rules) {
            std::smatch match;
            if (std::regex_search(remaining, match, rule.pattern)) {
                std::string matched = match[0];
                
                // Longest match rule
                if (matched.length() > bestMatch.length() ||
                    (matched.length() == bestMatch.length() && rule.priority < bestPriority)) {
                    bestMatch = matched;
                    bestType = rule.name;
                    bestPriority = rule.priority;
                }
            }
        }
        
        if (bestMatch.empty()) {
            throw std::runtime_error("No match at position " + std::to_string(pos));
        }
        
        tokens.push_back({bestType, bestMatch, pos});
        pos += bestMatch.length();
    }
    
    return tokens;
}
