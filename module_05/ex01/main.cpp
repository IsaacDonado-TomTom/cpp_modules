#include <Bureaucrat.hpp>
#include <Form.hpp>

int main(void)
{
    Form *one = new Form("one", 0, 0);
    Form *two = new Form("two", 1, 1);
    Bureaucrat* david = new Bureaucrat("David", 1);

    std::cout << std::endl << *one << std::endl << *two <<std::endl << *david <<std::endl <<std::endl;

    david->signForm(*one);
    david->signForm(*two);

    std::cout <<std::endl;
    delete david;delete one; delete two;


    one = new Form("one", 0, 0);
    two = new Form("two", 1, 1);
    Bureaucrat* isaac = new Bureaucrat("Isaac", 150);

    std::cout << std::endl << *one << std::endl << *two <<std::endl << *isaac <<std::endl <<std::endl;

    isaac->signForm(*one);
    isaac->signForm(*two);

    std::cout << std::endl;
    delete isaac;delete two; delete one;
    return (0);
}