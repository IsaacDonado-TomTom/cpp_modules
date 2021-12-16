#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <stdexcept>

class Span
{
    public:
    Span(unsigned int N);
    Span(const Span& src);
    ~Span();
    Span&   operator=(const Span& rhs);
    void    addNumber(int num);
    int     shortestSpan(void);
    int     longestSpan(void);

    ////////////////////////////////////////////////////
    //             addNumber Template                 //
    ////////////////////////////////////////////////////
    template <typename T>
    void addNumber(T begin, T end)
	{
		if (std::distance(begin, end) + this->_numbers.size() > this->_capacity)
			throw(std::runtime_error("Insufficient capacity"));
        else
	    	this->_numbers.insert(this->_numbers.end(), begin, end);
	}

    private:
    Span();
    unsigned int  _capacity;
    std::vector<int>    _numbers;
};

#endif