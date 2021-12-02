#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <Form.hpp>

class RobotomyRequestForm : public Form
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

    RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& src);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

    virtual void    execute(const Bureaucrat& executor) const throw(GradeTooHighException, GradeTooLowException, FormNotSignedException);
private:
    RobotomyRequestForm();
};

std::ostream&   operator<<(std::ostream& output, RobotomyRequestForm& form);

#endif