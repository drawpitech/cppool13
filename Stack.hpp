/*
** EPITECH PROJECT, 2024
** ppool13
** File description:
** Stack
*/

#pragma once

#include <exception>
#include <stack>

class Stack
{
   public:
    void push(double value);
    double pop();
    double top() const;

    void add();
    void sub();
    void mul();
    void div();

    class Error : public std::exception
    {
       public:
        enum class ErrorType
        {
            NOT_ENOUGH_OPERANDS,
            EMPTY_STACK,
        };

        Error(ErrorType type) : _type(type) {}
        const char *what() const noexcept override
        {
            switch (_type) {
                case ErrorType::NOT_ENOUGH_OPERANDS:
                    return "Not enough operands";
                default:
                case ErrorType::EMPTY_STACK:
                    return "Empty stack";
            }
        }

       private:
        ErrorType _type;
    };

   private:
    std::stack<double> _stack;
};
