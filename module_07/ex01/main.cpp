#include <iter.hpp>

struct Data
{
    Data() : name("blank") {}
    int id;
    std::string name;
};

std::ostream& operator<<(std::ostream& output, const Data& stuff)
{
    output << "ID[" << stuff.id << "] Name: " << stuff.name;
    return (output);
}

int main(void)
{
    int num_arr[5];
    int i;

    for (i=0;i<5;i++)
        num_arr[i] = i + 5;
    iter(num_arr, 5, generic_print);

    char char_arr[5];
    for (i=0;i<5;i++)
        char_arr[i] = i + 'a';
    iter(char_arr, 5, generic_print);

    Data stuff[5];
    for (i=0;i<5;i++)
        stuff[i].id = i + 1001;
    iter(stuff, 5, generic_print);

    for (i=-2;i<3;i++)
        num_arr[i+2] = i;
    iter(num_arr, 5, compare_to_one);
    return (0);
}