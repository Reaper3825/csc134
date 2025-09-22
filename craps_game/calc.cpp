#include "craps_game/calc.hpp"
#include <stdexcept> 
double calculate(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::invalid_argument("Division by zero!");
        return a / b;
    }
    throw std::invalid_argument("Unknown operator: " + op);
}
