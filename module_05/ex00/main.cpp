#include <Bureaucrat.hpp>

int main(void)
{
    Bureaucrat bob("Bob", 149);
    bob.decrementGrade();
    bob.decrementGrade();
    bob.decrementGrade();
    std::cout << bob << std::endl;
    bob.incrementGrade();
    bob.incrementGrade();
    bob.incrementGrade();
    bob.incrementGrade();
    std::cout << bob << std::endl;
    return (0);
}