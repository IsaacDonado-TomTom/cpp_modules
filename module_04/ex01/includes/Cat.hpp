#ifndef CAT_HPP
# define CAT_HPP
# include <Animal.hpp>
# include <Brain.hpp>
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

#endif