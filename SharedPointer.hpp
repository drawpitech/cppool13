/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** SharedPointer
*/

#pragma once

#include <cstddef>
#include <utility>

template <typename T>
class SharedPointer
{
   public:
    SharedPointer() = default;

    SharedPointer(T *ptr) : _ptr(ptr)
    {
        incrementCount();
    }

    SharedPointer(const SharedPointer &other)
        : _ptr(other._ptr), _count(other._count)
    {
        incrementCount();
    }

    ~SharedPointer()
    {
        decrementCount();
    }

    void swap(SharedPointer &other) noexcept
    {
        std::swap(_ptr, other._ptr);
        std::swap(_count, other._count);
    }

    void reset(T *ptr = nullptr) noexcept
    {
        decrementCount();
        _ptr = ptr;
        incrementCount();
    }

    std::size_t use_count() const
    {
        return (_count != nullptr) ? *_count : 0;
    }

    T *operator->() const
    {
        return _ptr;
    }

    T *get() const
    {
        return _ptr;
    }

    SharedPointer &operator=(T *ptr)
    {
        decrementCount();
        _ptr = ptr;
        incrementCount();
        return *this;
    }

    SharedPointer &operator=(const SharedPointer &other)
    {
        decrementCount();
        _count = other._count;
        _ptr = other._ptr;
        incrementCount();
        return *this;
    }

   private:
    T *_ptr = nullptr;
    std::size_t *_count = nullptr;

    void incrementCount()
    {
        if (_ptr == nullptr)
            return;
        if (_count == nullptr)
            _count = new std::size_t(1);
        else
            *_count += 1;
    }
    void decrementCount()
    {
        if (_count == nullptr)
            return;
        *_count -= 1;
        if (*_count == 0) {
            delete _ptr;
            delete _count;
        }
        _count = nullptr;
        _ptr = nullptr;
    }
};
