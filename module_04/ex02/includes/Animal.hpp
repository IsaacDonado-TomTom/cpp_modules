#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal& src);
    virtual ~Animal();

    Animal& operator=(const Animal& rhs);
    virtual const std::string&  get_type() const = 0;
    virtual void    makeSound() const = 0;
protected:
    std::string type;
};

#endif