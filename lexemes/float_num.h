#pragma once

#include "num_literal.h"

class Float_num : public Num_literal {
public:
    explicit Float_num(std::string data) : data_(std::move(data)) {}
    void Print() {
        std::cout << "Float_num" << ' ' << data_ << '\n';
    }
    std::string data_{};
};