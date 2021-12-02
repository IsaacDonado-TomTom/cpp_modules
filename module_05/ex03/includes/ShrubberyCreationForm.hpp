#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <Form.hpp>

class ShrubberyCreationForm : public Form
{
private:
    ShrubberyCreationForm();
public:

    class FormNotSignedException : public std::exception
    {
    private:
        std::string _msg;
    public:
        FormNotSignedException(const std::string& msg);
        ~FormNotSignedException() _NOEXCEPT;
        virtual const char* what() const throw();
    };


    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& rhs);

    virtual void    execute(const Bureaucrat& executor) const throw(GradeTooHighException, GradeTooLowException, FormNotSignedException);
};

std::ostream&   operator<<(std::ostream& output, ShrubberyCreationForm& form);

#endif