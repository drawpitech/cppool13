#include <iostream>
#include <string>

#include "../Algorithm.hpp"

int main()
{
    int a = 42;
    int b = 21;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "min(a, b) = " << ::min(a, b) << "\n";
    std::cout << "max(a, b) = " << ::max(a, b) << "\n";
    std::cout << "clamp(0, a, b) = " << ::clamp(0, a, b) << "\n";

    std::string c = "ghi";
    std::string d = "abc";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << "\n";
    std::cout << "min(c, d) = " << ::min(c, d) << "\n";
    std::cout << "max(c, d) = " << ::max(c, d) << "\n";
    std::cout << "clamp(\"def\", c, d) = "
              << ::clamp(std::string("def"), c, d) << "\n";
    return 0;
}
