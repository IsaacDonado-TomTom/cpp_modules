#ifndef CLASSES_HPP
# define CLASSES_HPP
# include <iostream>

class Brain {
public:
    Brain();
    ~Brain();
    Brain(const Brain& src);

    Brain&  operator=(const Brain& rhs);
    void    setIdea(int i, std::string idea);
    friend std::ostream& operator<<(std::ostream& output, const Brain& source);
protected:
    std::string ideas[100];
};


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

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& src);
    virtual ~Cat();

    Cat& operator=(const Cat& rhs);
    virtual const std::string& get_type() const;
    virtual void    makeSound() const;
    Brain*    get_brain() const;
private:
    Brain*  catBrain;
};

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& src);
    virtual ~Dog();

    Dog& operator=(const Dog& rhs);
    virtual const std::string& get_type() const;
    virtual void    makeSound() const;
    Brain*    get_brain() const;
private:
    Brain*  dogBrain;
};

#endif