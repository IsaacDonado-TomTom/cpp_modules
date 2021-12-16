#include "span.hpp"

Span::Span() : _capacity(0)
{
    // This should never run.
}

Span::Span(unsigned int N) : _capacity(N)
{
    this->_numbers.reserve(this->_capacity);
}

Span::Span(const Span& src) : _capacity(src._capacity), _numbers(src._numbers) { }

Span&   Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        this->_capacity = rhs._capacity;
        this->_numbers = rhs._numbers;
    }
    return (*this);
}

void    Span::addNumber(int num)
{
    if (this->_numbers.size() >= this->_capacity)
        throw std::range_error("Insufficient capacity for another number");
    else
        this->_numbers.push_back(num);
}

int Span::shortestSpan(void)
{
    if (this->_numbers.size() < 2)
    {
        throw std::runtime_error("Need more numbers to find a span");
        return (-1);
    }
    uint32_t result, temp;
    result = std::numeric_limits<uint32_t>::max();
    bool found = false;
    std::vector<int> copy(this->_numbers.size());
    copy.reserve(this->_capacity);
    std::copy(this->_numbers.begin(), this->_numbers.end(), copy.begin());
    std::sort(copy.begin(), copy.end());

    for (int i = 1; copy[i]; i++)
    {
        temp = copy[i] - copy[i-1];
        if (temp != 0 && temp <= result)
        {
            result = temp;
            found = true;
        }
    }
    if (result == std::numeric_limits<uint32_t>::max() && found == false)
    {
        throw std::runtime_error("No shortest span found");
        return (-1);
    }
    return (result);
}

int Span::longestSpan(void)
{
    if (this->_numbers.size() < 2)
    {
        throw std::runtime_error("Need more numbers to find a span");
        return (-1);
    }
    int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
    int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
    if (std::abs(max - min) < 1)
    {
        throw std::runtime_error("No longest span found");
        return (-1);
    }
    return (std::abs(max - min));
}

Span::~Span() {}