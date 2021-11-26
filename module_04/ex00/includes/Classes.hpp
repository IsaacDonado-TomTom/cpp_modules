#ifndef CLASSES_HPP
# define CLASSES_HPP
# include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal& src);
    virtual ~Animal();

    Animal& operator=(const Animal& rhs);
    virtual const std::string&  get_type() const;
    virtual void    makeSound() const;
protected:
    std::string type;
};

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& src);
    virtual ~Cat();

    Cat& operator=(const Cat& rhs);
    virtual const std::string& get_type() const;
    virtual void    makeSound() const;
};

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& src);
    virtual ~Dog();

    Dog& operator=(const Dog& rhs);
    virtual const std::string& get_type() const;
    virtual void    makeSound() const;
};

#endif