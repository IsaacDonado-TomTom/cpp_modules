#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
# include <ostream>
# include <Bureaucrat.hpp>

class Form
{
public:
    //////////////////////////////////////////////
    //         Exception nested classes         //
    //////////////////////////////////////////////
    class GradeTooHighException : public std::exception
    {
    private:
        std::string _msg;
    public:
        GradeTooHighException(const std::string& msg);
        ~GradeTooHighException() _NOEXCEPT;
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    private:
        std::string _msg;
    public:
        GradeTooLowException(const std::string& msg);
        ~GradeTooLowException() _NOEXCEPT;
        virtual const char* what() const throw();
    };


    //////////////////////////////////////////////
    //                Form  functions           //
    //////////////////////////////////////////////
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    ~Form();
    Form(const Form& src);
    Form&   operator=(const Form& rhs);
    const std::string&  getName() const;
    bool                isSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;
    void                beSigned(const Bureaucrat& person) throw(GradeTooLowException, GradeTooHighException);
private:
    const       std::string _name;
    bool        _signed;
    const int   _gradeToSign;
    const int   _gradeToExecute;
    Form();
};

std::ostream&   operator<<(std::ostream& output, Form& rhs);

#endif