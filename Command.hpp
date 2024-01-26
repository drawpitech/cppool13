/*
** EPITECH PROJECT, 2024
** ppool13
** File description:
** Command
*/

#pragma once

#include <functional>
#include <map>
#include <string>

class Command
{
   public:
    void registerCommand(
        const std::string& name, const std::function<void()>& function);
    void executeCommand(const std::string& name);

    class Error : public std::exception
    {
       public:
        Error(const std::string& msg) : _msg(msg) {}
        const char* what() const noexcept override
        {
            return _msg.c_str();
        }

       private:
        std::string _msg;
    };

   private:
    std::map<std::string, std::function<void()>> _map;
};
