#include <Classes.hpp>

// Brain class functions.

Brain::Brain()
{
    std::cout << "Brain created." << std::endl; 
    return ;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed." << std::endl;
    return ;
}

Brain::Brain(const Brain& src)
{
    int i;
    for (i=0; i < 100 ; ++i)
    {
        this->ideas[i] = src.ideas[i];
    }
    std::cout << "Brain copy constructor." << std::endl;
}

Brain&  Brain::operator=(const Brain& rhs)
{
    int i;
    if (this != &rhs)
    {
        for (i=0; i < 100 ; ++i)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    std::cout << "Brain assignment overload called." << std::endl;
    return *this;
}

void    Brain::setIdea(int i, std::string idea)
{
    i -= 1;
    if (i < 0 || i > 99)
        std::cout << "Unable to set idea." << std::endl;
    this->ideas[i] = idea;
    return ;
}

std::ostream& operator<<(std::ostream& output, const Brain& source)
{
    output << "Ideas: [ ";
    int i;
    for (i = 0 ; i < 100 ; ++i)
    {
        if (source.ideas[i].length() > 0)
            output << "Idea[" << i << "]: " << source.ideas[i] << ", ";
    }
    output << " ]" << std::endl;
    return output;
}

// Animal class functions.

Animal::Animal() : type("None")
{
    std::cout << "Generic Animal created." << std::endl;
    return ;
}

Animal::~Animal()
{
    std::cout << "Generic Animal deleted." << std::endl;
    return ;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Generic animal copy constructor called." << std::endl;
    this->type = src.get_type();
    return ;
}

Animal& Animal::operator=(const Animal& rhs)
{
    (void)rhs;
    std::cout << "Animal assignment overload called." << std::endl;
    this->type = rhs.type;
    return (*this);
}

const std::string&  Animal::get_type() const
{
    return (this->type);
}

void    Animal::makeSound() const
{
    std::cout << "" << std::endl;
    return ;
}

// Dog class functions.

Dog::Dog()
{
    Brain*  dogBrain = new Brain;
    this->type = "Dog";
    this->dogBrain = dogBrain;
    std::cout << "Dog created." << std::endl;
    return ;
}

Dog::~Dog()
{
    delete this->dogBrain;
    std::cout << "Dog deleted." << std::endl;
    return ;
}

Dog::Dog(const Dog& src)
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->type = src.get_type();
    this->dogBrain = new Brain(*src.get_brain());
    return ;
}

Dog& Dog::operator=(const Dog& rhs)
{
    (void)rhs;
    std::cout << "Dog assignment overload called." << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.get_type();
        this->dogBrain = rhs.get_brain();
    }
    return (*this);
}

const std::string&  Dog::get_type() const
{
    return (this->type);
}

Brain*    Dog::get_brain() const
{
    return (this->dogBrain);
}

void    Dog::makeSound() const
{
    std::cout << "Dog: Barf Barf... WrrrrrBARF!" << std::endl;
    return ;
}

// Cat class functions.

Cat::Cat()
{
    Brain*  catBrain = new Brain;
    this->catBrain = catBrain;
    this->type = "Cat";
    std::cout << "Cat created." << std::endl;
    return ;
}

Cat::~Cat()
{
    delete this->catBrain;
    std::cout << "Cat deleted." << std::endl;
    return ;
}

Cat::Cat(const Cat& src)
{
    std::cout << "Cat copy constructor called." << std::endl;
    this->catBrain = new Brain(*src.get_brain());
    this->type = src.get_type();
    return ;
}

Cat& Cat::operator=(const Cat& rhs)
{
    (void)rhs;
    std::cout << "Cat assignment overload called." << std::endl;
    if (this != &rhs)
    {
        this->catBrain = rhs.get_brain();
        this->type = rhs.get_type();
    }
    return (*this);
}

const std::string&  Cat::get_type() const
{
    return (this->type);
}

void    Cat::makeSound() const
{
    std::cout << "Cat: Meeeeeowwww... rrrrrmeeeowww!" << std::endl;
    return ;
}

Brain*    Cat::get_brain() const
{
    return (this->catBrain);
}