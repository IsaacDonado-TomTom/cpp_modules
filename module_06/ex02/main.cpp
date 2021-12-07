#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

Base*   generate(void)
{
    srand (time(NULL));
    int     x = static_cast<unsigned int>(rand() % 3 + 1);
    if (x == 1)
        return (new A);
    else if (x == 2)
        return (new B);
    else
        return (new C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    }
    catch(const std::exception& e){}
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
    }
    catch(const std::exception& e){}
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
    }
    catch(const std::exception& e){}
}

int main(void)
{
    std::cout << "Identifying with pointer: " << std::endl;
    Base*   one = generate();
    identify(one);
    delete one;

    std::cout << "Identifying with reference: " << std::endl;
    A two;
    B three;
    C four;
    identify(two);
    identify(three);
    identify(four);
    return (0);
}