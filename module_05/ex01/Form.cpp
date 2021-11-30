#include <Form.hpp>

Form::Form() : _name("Blank"), _gradeToSign(1), _gradeToExecute(1)
{
    // This should never run.
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form(...) constructor called." << std::endl;
    try
    {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw(GradeTooHighException("Grade to sign or execute form too high on construction!"));
        else if (gradeToSign > 150 || gradeToExecute > 150)
            throw(GradeTooLowException("Grade to sign or execute form too low on construction!"));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form::~Form()
{
    std::cout << "~Form() destructor called." << std::endl;
}

Form::Form(const Form& src) : _name(src.getName()), _signed(src.isSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
    std::cout << "Form(Form&) copy constructor called." << std::endl;
    try
    {
        if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
            throw(GradeTooHighException("Grade to sign or execute form too high on construction!"));
        else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
            throw(GradeTooLowException("Grade to sign or execute form too low on construction!"));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form&   Form::operator=(const Form& rhs)
{
    std::cout << "Form assignment operator called." << std::endl;
    if (this != &rhs)
    {
        Form* temp = new Form(rhs);
        return (*temp);
    }
    return (*this);
}

const std::string&  Form::getName() const
{
    return (this->_name);
}

bool    Form::isSigned() const
{
    return (this->_signed);
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->_gradeToExecute);
}

void    Form::beSigned(const Bureaucrat& person) throw(GradeTooHighException, GradeTooLowException)
{
    if (this->_gradeToSign < 1)
        throw (GradeTooHighException("Grade required by form too high to be signed by anyone. Highest possible is 1"));
    else if (this->_gradeToSign > 150)
        throw (GradeTooLowException("Grade required by form too low to be signed by anyone. Lowest possible is 150."));
    else if (person.getGrade() <= this->_gradeToSign)
    {
        //std::cout << person.getName() << " gradetosign:" << person.getGrade() << ".. grade to sign form:" << this->_gradeToSign << std::endl;  
        this->_signed = true;
    }
    else
        throw (GradeTooLowException("Grade required by form is too high for bureaucrat to sign. "));
}




////////////////////////////////////////////////////////////////////
//                    EXCEPTIONS DEFINITIONS                      //
////////////////////////////////////////////////////////////////////

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msg(msg) { }
Form::GradeTooHighException::~GradeTooHighException() throw() { }

const char* Form::GradeTooHighException::what() const throw()
{
    return (this->_msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msg(msg) { }
Form::GradeTooLowException::~GradeTooLowException() throw() { }

const char* Form::GradeTooLowException::what() const throw()
{
    return (this->_msg.c_str());
}



////////////////////////////////////////////////////////////////////////
//                   (<<) Operator Overload                           //
////////////////////////////////////////////////////////////////////////
std::ostream&   operator<<(std::ostream& output, Form& rhs)
{
    output << "Form[" << rhs.getName() << "] - Signed Status = [" << rhs.isSigned() << "] Grade to Sign = [" << rhs.getGradeToSign() << "] Grade to Execute = [" << rhs.getGradeToExecute() << "]";
    return (output);
}