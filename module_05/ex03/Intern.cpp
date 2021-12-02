#include <Intern.hpp>

Intern::Intern()
{
    std::cout << "Intern() constructor called." << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern() destructor called." << std::endl;
}

Intern::Intern(const Intern& src)
{
    (void)src;
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
    std::string formPool[3];
    formPool[0] = "ShrubberyCreationForm";
    formPool[1] = "RobotomyRequestForm";
    formPool[2] = "PresidentialPardonForm";
    Form*   funcPool[3];
    funcPool[0] = new ShrubberyCreationForm(target);
    funcPool[1] = new RobotomyRequestForm(target);
    funcPool[2] = new PresidentialPardonForm(target);
    bool found = false;
    for (int i = 0;i < 3; ++i)
    {
        if (!(formPool[i].compare(formName)))
        {
            std::cout << "\033[32m Form[" << formName << "] created.\033[39m" << std::endl;
            return (funcPool[i]);
        }
    }
    if (found == false)
        std::cout << "\033[31m Form[" << target << "] is not available.\033[39m" << std::endl;
    return (NULL);
}