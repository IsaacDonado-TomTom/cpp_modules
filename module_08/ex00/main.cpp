#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

void    test_list(void)
{
    std::list<int>                  list_item;
    std::list<int>::iterator        result;

    list_item.push_back(42);
    list_item.push_back(2);
    list_item.push_back(-32);
    list_item.push_back(100);
    list_item.push_back(1);

    try
    {
        result = easyfind(list_item, 0);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

void    test_vector(void)
{
    std::vector<int>            vector_array(5, 20);
    std::vector<int>::iterator  result;
    try
    {
        result = easyfind(vector_array, 20);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return ;
}

int main(void)
{
    test_list();
    test_vector();

    return (0);
}

