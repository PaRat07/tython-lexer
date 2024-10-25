#pragma once

#include "lex.h"
#include <string>
#include <utility>

class Identifier : public Lex {
public:
    explicit Identifier(std::string data) : name_(std::move(data)) {}
    void Print() {
        std::cout << "Identifier" << ' ' << name_ << '\n';
    }
    std::string name_;
};