#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm() : Form("Blank", 25, 5, "Blank") { }

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : Form("PresidentialPardonForm", 25, 5, target)
{
    std::cout << "Presidential(...) constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential(...) destructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : Form(src)
{
    std::cout << "Presidential(...) copy constructor called." << std::endl;
}

PresidentialPardonForm&    PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    std::cout << "Presidential(...) assignment called." << std::endl;
    if (this != &rhs)
    {
        PresidentialPardonForm*  temp;
        temp = new PresidentialPardonForm(rhs);
        return (*temp);
    }
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const throw(GradeTooHighException, GradeTooLowException, FormNotSignedException)
{
    if (this->isSigned() == true)
    {
        if (this->getGradeToExecute() < 1)
            throw (GradeTooHighException("\033[31mGrade required by form too high to be executed by anyone. Highest possible is 1\033[39m"));
        else if (this->getGradeToExecute() > 150)
            throw (GradeTooLowException("\033[31mGrade required by form too low to be executed by anyone. Lowest possible is 150.\033[39m"));
        else if (executor.getGrade() <= this->getGradeToExecute())
        {  
            std::cout << "\033[32m [" << this->getTarget() << "] has been pardoned by Zafod Beeblebrox.\033[39m" << std::endl;
        }
        else
            throw (GradeTooLowException("\033[31mGrade required by form is too high for bureaucrat to execute. \033[39m"));
    }
    else
        throw (FormNotSignedException("\033[31mForm requested to execute is not signed. \033[39m"));
    return ;
}



////////////////////////////////////////////////////////////////////
//                    EXCEPTIONS DEFINITIONS                      //
////////////////////////////////////////////////////////////////////
PresidentialPardonForm::FormNotSignedException::FormNotSignedException(const std::string& msg) : _msg(msg) { }
PresidentialPardonForm::FormNotSignedException::~FormNotSignedException() throw() { }
const char* PresidentialPardonForm::FormNotSignedException::what() const throw()
{
    return (this->_msg.c_str());
}

////////////////////////////////////////////////////////////////////////
//                   (<<) Operator Overload                           //
////////////////////////////////////////////////////////////////////////
std::ostream&   operator<<(std::ostream& output, PresidentialPardonForm& rhs)
{
    output << "Form[" << rhs.getName() << "] - Signed Status = [" << rhs.isSigned() << "] Grade to Sign = [" << rhs.getGradeToSign() << "] Grade to Execute = [" << rhs.getGradeToExecute() << "]";
    return (output);
}