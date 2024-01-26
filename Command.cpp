/*
** EPITECH PROJECT, 2024
** ppool13
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand(
    const std::string& name, const std::function<void()>& function)
{
    if (_map.find(name) != _map.end())
        throw Error("Already registered command");
    _map.insert(std::make_pair(name, function));
}

void Command::executeCommand(const std::string& name) {
    if (_map.find(name) == _map.end())
        throw Error("Unknow command");
    _map[name]();
}
