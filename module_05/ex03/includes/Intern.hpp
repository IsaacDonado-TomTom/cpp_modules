#ifndef INTERN_HPP
# define INTERN_HPP

# include <ShrubberyCreationForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <PresidentialPardonForm.hpp>

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern& src);
    Intern& operator=(const Intern& rhs);
    Form*    makeForm(const std::string& formName, const std::string& target);
};

# endif