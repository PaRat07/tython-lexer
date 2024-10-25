#pragma once

#include <string>

#include "literal.h"

class String_literal : public Literal {
public:
    explicit String_literal(std::string data) : data_(std::move(data)) {}
    void Print() {
        std::cout << "String_literal" << ' ' << data_ << '\n';
    }
    std::string data_;
};
