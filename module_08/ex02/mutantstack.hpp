#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &toCopy);
		~MutantStack(void);
		MutantStack& operator = (const MutantStack &toCopy);
		
		typedef    typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);
};

template<class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template<class T>
MutantStack<T>::MutantStack(const MutantStack & src) : std::stack<T>(src) {}

template<class T>
MutantStack<T>::~MutantStack(void) {}

template<class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &rhs){ this->c = rhs.c; return (*this); }

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) { return(this->c.begin()); }

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {	return(this->c.end()); }

#endif