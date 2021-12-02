#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main(void)
{
    Form *one = new ShrubberyCreationForm("Linda's backyard");
    Form *two = new RobotomyRequestForm("Dereck");
    Form *three = new PresidentialPardonForm("Felipe");
    std::cout << *one << std::endl;
    std::cout << *two << std::endl;
    std::cout << *three << std::endl;

    Bureaucrat *peter = new Bureaucrat("Peter", 151);
    Bureaucrat *joseph = new Bureaucrat("Joseph", 145);
    Bureaucrat *mario = new Bureaucrat("Mario", 72);
    Bureaucrat *dereck = new Bureaucrat("Dereck", 25);
    Bureaucrat *mary = new Bureaucrat("Mary", 5);
    std::cout << *peter << std::endl;
    std::cout << *joseph << std::endl;
    std::cout << *mario << std::endl;
    std::cout << *dereck << std::endl;
    std::cout << *mary << std::endl;

    peter->signForm(*one);
    peter->executeForm(*one);

    joseph->signForm(*one);
    joseph->executeForm(*one);

    mario->signForm(*one);
    mario->executeForm(*one);

    mario->signForm(*two);
    mario->executeForm(*two);

    dereck->signForm(*two);
    dereck->executeForm(*two);

    dereck->signForm(*three);
    dereck->executeForm(*three);

    mary->signForm(*three);
    mary->executeForm(*three);

    
    delete one; delete two; delete three; delete joseph; delete mario; delete dereck; delete mary;
    return (0);
}