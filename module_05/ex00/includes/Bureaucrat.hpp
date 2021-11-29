#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include <ostream>

class Bureaucrat 
{
private:
    const std::string   _name;
    int                 _grade;
    Bureaucrat();
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
    //           Bureacrat  functions           //
    //////////////////////////////////////////////
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& rhs);

    int                 getGrade() const;
    const std::string&  getName() const;
    void                incrementGrade() throw(GradeTooHighException);
    void                decrementGrade() throw(GradeTooLowException);
};

std::ostream&   operator<<(std::ostream& output, Bureaucrat& object);

#endif