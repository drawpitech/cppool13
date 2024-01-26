/*
** EPITECH PROJECT, 2024
** ppool13
** File description:
** Algorithm
*/

#pragma once

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T clamp(T value, T min, T max)
{
    return ::min(::max(value, min), max);
}
