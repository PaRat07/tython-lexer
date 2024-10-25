#include <iostream>
#include "lexer.h"

int main() {
    Lexer lexer;
    lexer.Scan("in.txt");
    lexer.Print();
    return 0;
}
