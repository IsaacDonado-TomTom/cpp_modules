#include <Intern.hpp>

Intern::Intern()
{
    this->forms[0].name = "ShrubberyCreationForm";
    this->forms[1].name = "RobotomyRequestForm";
    this->forms[2].name = "PresidentialPardonForm";
    this->forms[0].f = &Intern::Shrubbery;
    this->forms[1].f = &Intern::Robotomy;
    this->forms[2].f = &Intern::Presidential;
    std::cout << "Intern() constructor called." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern() destructor called." << std::endl;
}

Intern::Intern(const Intern& src)
{
    (void)src;
    this->forms[0].name = "ShrubberyCreationForm";
    this->forms[1].name = "RobotomyRequestForm";
    this->forms[2].name = "PresidentialPardonForm";
    this->forms[0].f = &Intern::Shrubbery;
    this->forms[1].f = &Intern::Robotomy;
    this->forms[2].f = &Intern::Presidential;
    std::cout << "Intern(Intern&) copy constructor called." << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
    if (this != &rhs)
        return (*(new Intern()));
    return (*this);
}

Form*   Intern::makeForm(const std::string& formName, const std::string& target)
{
    for (int i = 0;i < 3; ++i)
    {
        if (!(this->forms[i].name.compare(formName)))
        {
            std::cout << "\033[32m Form[" << formName << "] created.\033[39m" << std::endl;
            return (this->*(this->forms[i].f))(target);
        }
    }
        std::cout << "\033[31m Form[" << formName << "] is not available.\033[39m" << std::endl;
    return (NULL);
}

Form *Intern::Shrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

Form *Intern::Presidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

Form *Intern::Robotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}
