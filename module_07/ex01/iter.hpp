#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T>
void    iter(T* array, size_t size, void (*f)(const T& item))
{
    for (size_t i = 0; i < size; i++)
    {
        try
        {
            f(array[i]);
        }
        catch (std::exception& e)
        {
            std::cout << "Array out of bounds" << std::endl;
        }
    }
}

template<typename T>
void    generic_print(const T& item)
{
    std::cout << item << std::endl;
}

template<typename T>
void    compare_to_one(const T& item)
{
    if (item > 1)
        std::cout << "Item is bigger than one" << std::endl;
    else if (item == 1)
        std::cout << "Item is equal to one" << std::endl;
    else
        std::cout << "Item is less than one" << std::endl;
}

#endif