#include <ShrubberyCreationForm.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Blank", 145, 137, "Blank")
{
    // This should never run.
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << "Shrubbery(...) constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery(...) destructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : Form(src)
{
    std::cout << "Shrubbery(Form&) copy constructor called." << std::endl;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    std::cout << "Shrubbery assignment operator called." << std::endl;
    if (this != &rhs)
    {
        ShrubberyCreationForm*  temp;
        temp = new ShrubberyCreationForm(rhs);
        return (*temp);
    }
    return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const throw(GradeTooHighException, GradeTooLowException, FormNotSignedException)
{
    if (this->isSigned() == true)
    {
        if (this->getGradeToExecute() < 1)
            throw (GradeTooHighException("\033[31mGrade required by form too high to be executed by anyone. Highest possible is 1\033[39m"));
        else if (this->getGradeToExecute() > 150)
            throw (GradeTooLowException("\033[31mGrade required by form too low to be executed by anyone. Lowest possible is 150.\033[39m"));
        else if (executor.getGrade() <= this->getGradeToExecute())
        {  
            // Plant the tree!
            std::string     filename = this->getTarget() + "_shrubbery";
            std::ofstream   outfile(filename.c_str());
            if (outfile.is_open())
            {
                outfile <<   "     ccee88oo" << std::endl;
                outfile <<   "  C8O8O8Q8PoOb o8oo" << std::endl;
                outfile <<   " dOB69QO8PdUOpugoO9bD" << std::endl;
                outfile <<   "CgggbU8OU qOp qOdoUOdcb" << std::endl;
                outfile <<   "    6OuU  /p u gcoUodpP" << std::endl;
                outfile <<   "      \\\\//  /douUP" << std::endl;
                outfile <<   "        \\\\////" << std::endl;
                outfile <<   "         |||/\\" << std::endl;
                outfile <<   "         |||\\/" << std::endl;
                outfile <<   "         |||||" << std::endl;
                outfile <<   "   .....//||||\\...." << std::endl;
                outfile.close();
            }
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
ShrubberyCreationForm::FormNotSignedException::FormNotSignedException(const std::string& msg) : _msg(msg) { }
ShrubberyCreationForm::FormNotSignedException::~FormNotSignedException() throw() { }
const char* ShrubberyCreationForm::FormNotSignedException::what() const throw()
{
    return (this->_msg.c_str());
}

////////////////////////////////////////////////////////////////////////
//                   (<<) Operator Overload                           //
////////////////////////////////////////////////////////////////////////
std::ostream&   operator<<(std::ostream& output, ShrubberyCreationForm& rhs)
{
    output << "Form[" << rhs.getName() << "] - Signed Status = [" << rhs.isSigned() << "] Grade to Sign = [" << rhs.getGradeToSign() << "] Grade to Execute = [" << rhs.getGradeToExecute() << "]";
    return (output);
}