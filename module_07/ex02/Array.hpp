#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <stdexcept>

template< typename T >
class Array
{
    private:
        T*              _array;
        unsigned int    _size;
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array& src);
        Array<T>&  operator=(const Array& rhs);
        ~Array(void);
        unsigned int    size(void) const;
        T&  operator[](unsigned int i);
};

template< typename T >
Array<T>::Array(void)
{
    this->_array = NULL;
    this->_size = 0;
}

template< typename T >
Array<T>::Array(unsigned int n)
{
    this->_size = n;
    this->_array = new T[n]();
}

template< typename T >
Array<T>::Array(const Array& src)
{
    this->_array = new T[src.size()];
    this->_size = src.size();
    for (unsigned int i = 0; i< this->_size ; i++)
        this->_array[i] = src._array[i];
}

template< typename T >
Array<T>&  Array<T>::operator=(const Array& rhs)
{
    if (this == &rhs)
    {
        Array* temp = new Array(rhs);
        return (*temp);
    }
    return (*this);
}

template< typename T >
Array<T>::~Array(void)
{
    if (this->_array != NULL)
        delete [] this->_array;
}

template< typename T >
unsigned int    Array<T>::size(void) const
{
    return (this->_size);
}

template< typename T >
T&  Array<T>::operator[](unsigned int i)
{
    if (i >= this->_size)
        throw std::out_of_range("Out of range!");
    return (this->_array[i]);
}


#endif