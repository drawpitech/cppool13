#include <iostream>

#include "../Stack.hpp"

int main()
{
    Stack stack;
    stack.push(42.21);
    stack.push(84.42);
    stack.push(21.12);
    stack.add();
    stack.div();
    try {
        stack.mul();
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    std::cout << stack.top() << "\n";
    return 0;
}
