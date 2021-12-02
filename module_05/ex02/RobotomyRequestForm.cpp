#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm() : Form("Blank", 72, 45, "Blank") { }

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : Form("RobotomyRequestForm", 72, 45, target)
{
    std::cout << "Robotomy(...) constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy(...) destructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : Form(src)
{
    std::cout << "Robotomy(...) copy constructor called." << std::endl;
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    std::cout << "Robotomy(...) assignment called." << std::endl;
    if (this != &rhs)
    {
        RobotomyRequestForm*  temp;
        temp = new RobotomyRequestForm(rhs);
        return (*temp);
    }
    return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const throw(GradeTooHighException, GradeTooLowException, FormNotSignedException)
{
    if (this->isSigned() == true)
    {
        if (this->getGradeToExecute() < 1)
            throw (GradeTooHighException("\033[31mGrade required by form too high to be executed by anyone. Highest possible is 1\033[39m"));
        else if (this->getGradeToExecute() > 150)
            throw (GradeTooLowException("\033[31mGrade required by form too low to be executed by anyone. Lowest possible is 150.\033[39m"));
        else if (executor.getGrade() <= this->getGradeToExecute())
        {  
            std::cout << "\033[32m *Drilling noises* [" << this->getTarget() << "] has been robotomized successfully 50% of the time.\033[39m" << std::endl;
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
RobotomyRequestForm::FormNotSignedException::FormNotSignedException(const std::string& msg) : _msg(msg) { }
RobotomyRequestForm::FormNotSignedException::~FormNotSignedException() throw() { }
const char* RobotomyRequestForm::FormNotSignedException::what() const throw()
{
    return (this->_msg.c_str());
}

////////////////////////////////////////////////////////////////////////
//                   (<<) Operator Overload                           //
////////////////////////////////////////////////////////////////////////
std::ostream&   operator<<(std::ostream& output, RobotomyRequestForm& rhs)
{
    output << "Form[" << rhs.getName() << "] - Signed Status = [" << rhs.isSigned() << "] Grade to Sign = [" << rhs.getGradeToSign() << "] Grade to Execute = [" << rhs.getGradeToExecute() << "]";
    return (output);
}