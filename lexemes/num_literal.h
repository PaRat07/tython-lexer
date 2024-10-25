#pragma once

#include <cstdint>

#include "literal.h"

class Num_literal : Literal {
public:
    int64_t data_{};
};