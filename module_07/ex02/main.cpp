#include <Array.hpp>
#include <iostream>

void    int_arr(void)
{
    unsigned int i;
    Array<int> arr_ints(5);

    std::cout << "Creating new int array..." << std::endl;

    for (i = 0;i < arr_ints.size(); i++)
        arr_ints[i] = 42 + i;
    for (i = 0;i < arr_ints.size(); i++)
        std::cout << "arr_ints[" << i << "]: " << arr_ints[i] <<  "... ";
    std::cout << std::endl;

    std::cout << "size(): " << arr_ints.size() << std::endl;

    std::cout << "Will try to access arr_ints[5]..." << std::endl;
    try
    {
        std::cout << arr_ints[5] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void    string_arr(void)
{
    unsigned int i;
    Array<std::string> arr_strings(5);

    std::cout << "Creating new std::string array..." << std::endl;

    for (i = 0;i < arr_strings.size(); i++)
    {
        arr_strings[i] = "Blank";
        arr_strings[i][0] = arr_strings[i][0] + i;
    }
    for (i = 0;i < arr_strings.size(); i++)
        std::cout << "arr_strings[" << i << "]: " << arr_strings[i] <<  "... ";
    std::cout << std::endl;

    std::cout << "size(): " << arr_strings.size() << std::endl;
}

void    copy_operator()
{
    std::cout << std::endl << "Creating an array, copying to another by assignment operator." << std::endl;
    unsigned int i;
    Array<int> arr_ints(5);
    for (i = 0;i < arr_ints.size(); i++)
        arr_ints[i] = 42 + i;
    Array<int> arr_ints_copy;
    arr_ints_copy = arr_ints;
    std::cout << std::endl << "displaying original." << std::endl;
    for (i = 0;i < arr_ints.size(); i++)
        std::cout << "arr_ints[" << i << "]: " << arr_ints[i] <<  " - Address: " << &arr_ints[i] << "... ";
    std::cout << std::endl << "displaying copy." << std::endl;
    for (i = 0;i < arr_ints_copy.size(); i++)
        std::cout << "arr_ints_copy[" << i << "]: " << arr_ints_copy[i] <<  " - Address: " << &arr_ints_copy[i] << "... ";
    std::cout << std::endl;
}

void    copy_constructor()
{
    unsigned int i;
    std::cout << std::endl << "Creating an array of strings, copying to another by copy contructor." << std::endl;
    Array<std::string> arr_strings(5);
    for (i = 0;i < arr_strings.size(); i++)
    {
        arr_strings[i] = "Blank";
        arr_strings[i][0] = arr_strings[i][0] + i;
    }
    Array<std::string> arr_strings_copy(arr_strings);
    std::cout << std::endl << "displaying original." << std::endl;
    for (i = 0;i < arr_strings.size(); i++)
        std::cout << "arr_strings[" << i << ": " << arr_strings[i] <<  " - Address: " << &arr_strings[i] << "... ";
    std::cout << std::endl << "displaying copy." << std::endl;
    for (i = 0;i < arr_strings_copy.size(); i++)
        std::cout << "arr_strings_copy[" << i << ": " << arr_strings_copy[i] <<  " - Address: " << &arr_strings_copy[i] << "... ";
    std::cout << std::endl;
}

int main(void)
{
    int_arr();
    string_arr();
    copy_operator();
    copy_constructor();
    return (0);
}