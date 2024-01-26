/*
** EPITECH PROJECT, 2024
** ppool13
** File description:
** UniquePointer
*/

#pragma once

#include <utility>

template <typename Type>
class UniquePointer
{
   public:
    UniquePointer() = default;
    UniquePointer(Type *ptr) : _ptr(ptr) {}
    UniquePointer(const UniquePointer &other) = delete;

    ~UniquePointer()
    {
        delete _ptr;
    }

    void swap(UniquePointer &other) noexcept
    {
        std::swap(_ptr, other._ptr);
    }

    void reset(Type *ptr = nullptr) noexcept
    {
        delete _ptr;
        _ptr = ptr;
    }

    Type *operator->() const
    {
        return _ptr;
    }

    Type *get() const
    {
        return _ptr;
    }

    UniquePointer &operator=(Type *ptr)
    {
        delete _ptr;
        _ptr = ptr;
        return *this;
    }
    UniquePointer &operator=(UniquePointer &other) = delete;

   private:
    Type *_ptr = nullptr;
};
