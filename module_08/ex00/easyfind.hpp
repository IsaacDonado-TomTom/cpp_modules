#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template< typename T >
typename T::iterator easyfind(T& haystack, const int& needle)
{
    typename T::iterator   result;
    result = std::find(haystack.begin(), haystack.end(), needle);
    if (needle != *result && needle != haystack.back())
        throw std::runtime_error("Unable to find value");
    return (result);
}

#endif