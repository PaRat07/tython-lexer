#pragma once

#include "lex.h"
#include <string>
#include <utility>

class Keyword : public Lex {
public:
    explicit Keyword(std::string data) : data_(std::move(data)) {}
    void Print() {
        std::cout << "Keyword" << ' ' << data_ << '\n';
    }
    std::string data_;
};