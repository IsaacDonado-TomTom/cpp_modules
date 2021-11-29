#ifndef DOG_HPP
# define DOG_HPP
# include <Animal.hpp>
# include <Brain.hpp>
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