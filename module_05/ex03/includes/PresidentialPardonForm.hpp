#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <Form.hpp>

class PresidentialPardonForm : public Form
{
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

    PresidentialPardonForm(const std::string& target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

    virtual void    execute(const Bureaucrat& executor) const throw(GradeTooHighException, GradeTooLowException, FormNotSignedException);
private:
    PresidentialPardonForm();
};

std::ostream&   operator<<(std::ostream& output, PresidentialPardonForm& form);

#endif