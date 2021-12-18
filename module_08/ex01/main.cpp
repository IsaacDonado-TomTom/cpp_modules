#include "span.hpp"
#include <iostream>
#include <vector>
#include <list>

void    subject_test(void)
{
    std::cout << "Subject sample test: " << std::endl;
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl << std::endl;
    return ;
}

void    large_range_test(void)
{
     std::cout << "Large number of numbers test: " << std::endl;
    std::vector<int>    range;

    srand(time(NULL));
    for (int i = 0 ; i < 10001 ; i++)
    {
        range.push_back(std::rand() % 10000);
    }

    Span one(10001);
    one.addNumber(range.begin(), range.end());

    uint32_t largest, shortest;

    try
    {
        largest = one.longestSpan();
        shortest = one.shortestSpan();
        std::cout << "LongestSpan: " << largest << std::endl;
        std::cout << "ShortestSpan: " << shortest << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;

    return ;
}

void    large_range_negative_test(void)
{
    std::cout << "Large range test with negative numbers: " << std::endl;
    std::list<int> range;
	for (int i = 0; i < 20000; i++)
		range.push_back((std::rand() % 200000) - 200000);

	Span two(20000);
    //Span two(2000); //Check insufficient capacity exception.
	two.addNumber(range.begin(), range.end());

	try
	{
		uint32_t ShortestSpan, LongestSpan;
		ShortestSpan = two.shortestSpan();
		LongestSpan = two.longestSpan();
		std::cout << "Shortest Span: " << ShortestSpan << std::endl << "Longests Span: " << LongestSpan << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    std::cout << std::endl;
    return ;
}

int    main(void)
{
    subject_test();
    large_range_test();
    large_range_negative_test();
    return (0);
}