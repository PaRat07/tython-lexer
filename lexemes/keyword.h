#pragma once

#include "lex.h"
#include <string>

class Keyword : public Lex {
public:
    std::string data_;
};