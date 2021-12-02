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
    Form *Shrubbery(std::string target);
    Form *Presidential(std::string target);
    Form *Robotomy(std::string target);
    typedef struct s_forms
    {
        std::string name;
        Form*   (Intern::*f)(std::string);
    }              t_forms;
    t_forms forms[3];
};

# endif