#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template< typename T >
void    swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
    return ;
}

template< typename T>
const T&    min(const T& a, const T& b)
{
    if (b <= a)
        return b;
    else
        return a;
}

template< typename T>
const T&    max(const T& a, const T& b)
{
    if (b >= a)
        return b;
    else
        return a;
}

#endif