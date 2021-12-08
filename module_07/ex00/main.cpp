#include <whatever.hpp>
#include <iostream>

void    example_test()
{
    std::cout << std::endl << "Test on subject sheet. " << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int main(void)
{
    int a = 42;
    int b = 24;

    std::cout << "Swap testing." << std::endl;

    std::string str1 = "First";
    std::string str2 = "Second";

    std::cout << "a: " << a << " b: " << b << std::endl;  
    ::swap(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;

    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl;  
    ::swap(str1, str2);
    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl;  


    std::cout << std::endl << std::endl << "min() testing." << std::endl;

    a = 42;
    b = 24;
    std::cout << "min 42 or 24: " << ::min(a, b) << std::endl;
    b = 42;
    std::cout << "a and b are both 42, does it return b's address? " << std::endl;
    std::cout << "b address: " << &b << " min return: " << &(::min(a, b)) << std::endl;

    std::cout << "min str1(First, Second): " << ::min(str1, str2) << std::endl;
    str2 = "First";
    std::cout << "str1 and str2 are both First, does it return str2's address? " << std::endl;
    std::cout << "str2 address: " << &str2 << " min return: " << &(::min(str1, str2)) << std::endl;

    std::cout << std::endl << std::endl << "max() testing." << std::endl;


    a = 42;
    b = 24;
    std::cout << "max 42 or 24: " << ::max(a, b) << std::endl;
    b = 42;
    std::cout << "a and b are both 42, does it return b's address? " << std::endl;
    std::cout << "b address: " << &b << " max return: " << &(::max(a, b)) << std::endl;
    str2 = "Second";
    std::cout << "max str1(First, Second): " << ::max(str1, str2) << std::endl;

    std::string* str3 = new std::string("First");
    std::string* str4 = new std::string("First");
    std::cout << "str3 and str4 are both First, does it return str4's address?" << std::endl;
    std::cout << "str4 address: " << std::addressof(str4) << " max return: " << std::addressof(::max(str3, str4)) << std::endl;
    delete str3; delete str4;

    example_test();


    return (0);
}