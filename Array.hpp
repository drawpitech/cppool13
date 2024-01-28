/*
** EPITECH PROJECT, 2024
** ppool13
** File description:
** Array
*/

#pragma once

#include <array>
#include <functional>
#include <iostream>

template <typename Type, std::size_t _size>
class Array
{
   public:
    std::size_t size() const
    {
        return _size;
    }

    void forEach(const std::function<void(const Type &)> &task) const
    {
        for (auto &e : _array)
            task(e);
    }

    Type &operator[](std::size_t index)
    {
        if (index >= _size)
            throw OutOfRangeException();
        return _array.at(index);
    }

    const Type &operator[](std::size_t index) const
    {
        if (index >= _size)
            throw OutOfRangeException();
        return _array.at(index);
    }

    template <typename U>
    Array<U, _size> convert(
        const std::function<U(const Type &)> &converter) const
    {
        Array<U, _size> res;
        for (size_t i = 0; i < _size; i++)
            res[i] = converter(_array[i]);
        return res;
    }

    class OutOfRangeException : public std::exception
    {
       public:
        const char *what() const noexcept override
        {
            return "Out of range";
        }
    };

   private:
    std::array<Type, _size> _array{0};
};

template <typename Type, std::size_t _size>
std::ostream &operator<<(std::ostream &os, const Array<Type, _size> &array)
{
    os << "[";
    for (std::size_t i = 0; i < array.size(); i++)
        os << (i ? ", " : "") << array[i];
    os << "]";
    return os;
}
