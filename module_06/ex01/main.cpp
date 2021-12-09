#include <iostream>
#include <stdint.h>

typedef struct s_data
{
    std::string str1;
    std::string str2;
}       t_data;


uintptr_t serialize(t_data* data)
{
    uintptr_t serial;

    serial = reinterpret_cast<uintptr_t>(data);
    return (serial);
}

t_data *deserialize(uintptr_t serial)
{
    t_data *data;
    data = reinterpret_cast<t_data*>(serial);
    return (data);
}

int main(void)
{
    t_data *one = new t_data;
    t_data *two;

    one->str1 = "Hello";
    one->str2 = "World!";

    std::cout << "one->str1: " << one->str1 << std::endl;
    std::cout << "one->str2: " << one->str2 << std::endl;

    uintptr_t serial = serialize(one);

    std::cout << "Serial(address) of one: " << serial << std::endl;
    std::cout << "Serial(address) of two: " << two << std::endl;

    two = deserialize(serial);

    std::cout << "Address of one: " << one << std::endl;
    std::cout << "Address of two: " << two << std::endl;

    std::cout << "two->str1: " << two->str1 << std::endl;
    std::cout << "two->str2: " << two->str2 << std::endl;

    if (one == two)
        std::cout << "Successfully pointing to the same address using serialize." << std::endl;
    
    delete one;

    return (0);
}