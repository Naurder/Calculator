#include <iostream>
#include <cmath>
#include <unordered_map>
#include <functional>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    float num1, num2;
    char op;

    // Prompt for first number
    std::cout << "Enter a Number: ";
    std::cin >> num1;

    // Prompt for operator
    std::cout << "Enter an Operator (+, -, *, /, ^ for power, r for square root): ";
    std::cin >> op;

    // Define operations with lambda functions
    std::unordered_map<char, std::function<float(float, float)>> operations = {
        {'+', [](float a, float b) { return a + b; }},
        {'-', [](float a, float b) { return a - b; }},
        {'*', [](float a, float b) { return a * b; }},
        {'/', [](float a, float b) { return b != 0 ? a / b : NAN; }},
        {'^', [](float a, float b) { return pow(a, b); }}
    };

    // Handle square root operation separately as it only requires one operand
    if (op == 'r') {
        if (num1 >= 0) {
            std::cout << "Result: " << sqrt(num1) << '\n';
        }
        else {
            std::cout << "Error: Cannot calculate square root of a negative number.\n";
        }
    }
    else {
        // For other operations, get the second number
        std::cout << "Enter another Number: ";
        std::cin >> num2;

        // Perform the operation using the map
        if (operations.count(op)) {
            float result = operations[op](num1, num2);
            if (std::isnan(result)) {
                std::cout << "Error: Division by zero.\n";
            }
            else {
                std::cout << "Result: " << result << '\n';
            }
        }
        else {
            std::cout << "Error: Invalid operator.\n";
        }
    }

    return 0;
}