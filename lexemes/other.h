#pragma once

#include <string>

#include "lex.h"

class Other : public Lex {
public:
    explicit Other(std::string data) : data_(std::move(data)) {}
    void Print() {
        std::cout << "other" << ' ' << data_ << '\n';
    }
    std::string data_;
};
