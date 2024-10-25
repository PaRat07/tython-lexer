#pragma once

#include "lex.h"
#include <string>

class Operator : public Lex {
public:
     explicit Operator(std::string data) : data_(std::move(data)) {}
     void Print() {
          std::cout << "Operator" << ' ' << data_ << '\n';
     }
     std::string data_;
};
