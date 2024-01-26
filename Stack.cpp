/*
** EPITECH PROJECT, 2024
** ppool13
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value)
{
    _stack.push(value);
}

double Stack::pop() {
    if (_stack.empty())
        throw Error(Error::ErrorType::EMPTY_STACK);

    double value = _stack.top();
    _stack.pop();
    return value;
}

double Stack::top() const {
    if (_stack.empty())
        throw Error(Error::ErrorType::EMPTY_STACK);
    return _stack.top();
}

void Stack::add() {
    if (_stack.size() < 2)
        throw Error(Error::ErrorType::NOT_ENOUGH_OPERANDS);
    push(pop() + pop());
}

void Stack::sub() {
    if (_stack.size() < 2)
        throw Error(Error::ErrorType::NOT_ENOUGH_OPERANDS);
    push(pop() - pop());
}

void Stack::mul() {
    if (_stack.size() < 2)
        throw Error(Error::ErrorType::NOT_ENOUGH_OPERANDS);
    push(pop() * pop());
}

void Stack::div() {
    if (_stack.size() < 2)
        throw Error(Error::ErrorType::NOT_ENOUGH_OPERANDS);
    push(pop() / pop());
}
