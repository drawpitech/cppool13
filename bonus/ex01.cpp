#include <iostream>

#include "../Array.hpp"

int main()
{
    Array<int, 3> array;
    try {
        array[0] = 21;
        array[1] = 42;
        array[2] = 84;
        array[3] = 84;
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    std::cout << array << "\n";
    array
        .convert<float>(
            [](const int& v) { return static_cast<float>(v) / 10.F; })
        .forEach([](const float& v) { std::cout << v << "\n"; });
    return 0;
}
