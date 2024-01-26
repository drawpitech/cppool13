#include <iostream>

#include "../Command.hpp"
#include "../Stack.hpp"

int main()
{
    Command command;
    Stack stack;
    try {
        command.registerCommand("push", [&stack]() { stack.push(4.2); });
        command.registerCommand(
            "display", [&stack]() { std::cout << stack.top() << "\n"; });
        command.registerCommand("add", [&stack]() { stack.add(); });
        command.registerCommand("sub", [&stack]() { stack.sub(); });
        command.registerCommand("mul", [&stack]() { stack.mul(); });
        command.registerCommand("div", [&stack]() { stack.div(); });
        command.registerCommand("display", []() {});
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    try {
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("push");
        command.executeCommand("add");
        command.executeCommand("div");
        command.executeCommand("display");
        command.executeCommand("nau");
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}
