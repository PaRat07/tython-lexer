#pragma once

#include <cstdint>

#include "num_literal.h"

class Int_num : public Num_literal {
public:
    explicit Int_num(const std::string& data) : data_(std::stol(data)) {}
    void Print() {
        std::cout << "Int_num" << ' ' << data_ << '\n';
    }
    int64_t data_{};
};