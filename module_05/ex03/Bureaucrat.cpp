#include <Bureaucrat.hpp>
#include <Form.hpp>

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    try
    {
        if (grade < 1)
            throw GradeTooHighException("Grade of spawning bureaucrat too high!");
        else if (grade > 150)
            throw GradeTooLowException("Grade of spawning bureaucrat too low!");
        else
            this->_grade = grade;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
        this->_grade = 150;
    }
    std::cout << "Bureaucrat [" << this->_name << "] spawned." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat [" << this->_name << "] gone." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName())
{
    this->_grade = src.getGrade();
    std::cout << "Bureaucrat [" << this->_name << "] copied." << std::endl;
    return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
    {
        Bureaucrat* temp = new Bureaucrat(rhs);
        std::cout << "Bureaucrat [" << temp->_name << "] assigned." << std::endl;
        return (*temp);
    }
    std::cout << "Bureaucrat [" << this->_name << "] assigned." << std::endl;
    return (*this);
}

const std::string& Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    try
    {
        if ((this->_grade - 1) < 1)
            throw GradeTooHighException("Grade incrementation too high!");
        else
            this->_grade = this->_grade - 1;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
    try
    {
        if ((this->_grade + 1) > 150)
            throw GradeTooLowException("Grade decrementation too low!");
        else
            this->_grade = this->_grade + 1;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    Bureaucrat::signForm(Form& form) const
{
    std::string str;
    if (form.getGradeToSign() < 1)
        str = "\033[31m because grade to sign form is unreasonably high, get a new form.\033[39m";
    else if (form.getGradeToSign() > 150)
        str = "\033[31m because grade to sign form is unreasonably low, get a new form.\033[39m";
    else
        str = "\033[31m due to bureacrat grade being too low.\033[39m";

    try
    {
        form.beSigned(*this);
        std::cout << "\033[32mBureaucrat[" << this->_name << "] has successfully signed form[" << form.getName() << "]\033[39m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' << "\033[31mBureaucrat[" << this->_name << "] was unable to sign[" << form.getName() << "]\033[39m" << str << std::endl;
    }
}

void    Bureaucrat::executeForm(const Form& form) const
{
    try
    {
        form.execute(*this);
        std::cout << "\033[32mBureaucrat[" << this->_name << "] has successfully executed form[" << form.getName() << "]\033[39m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n' << "\033[31mBureaucrat[" << this->_name << "] was unable to execute[" << form.getName() << "]\033[39m" <<  std::endl;
    }
}

////////////////////////////////////////////////////////////////////
//                    EXCEPTIONS DEFINITIONS                      //
////////////////////////////////////////////////////////////////////

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msg(msg) { }
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() { }
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (this->_msg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msg(msg) { }
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() { }
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (this->_msg.c_str());
}


////////////////////////////////////////////////////////////////////////
//                   (<<) Operator Overload                           //
////////////////////////////////////////////////////////////////////////

std::ostream&   operator<<(std::ostream& output, Bureaucrat& object)
{
    output << "[" << object.getName() << "] - Bureacrat Grade: " << object.getGrade();
    return (output);
}