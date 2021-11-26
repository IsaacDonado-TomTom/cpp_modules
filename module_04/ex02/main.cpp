#include <Classes.hpp>

int main(void)
{
    const Dog* bob = new Dog();
    const Animal* rob = new Cat();

    bob->get_brain()->setIdea(3, "Random");
    const Dog* kelly = new Dog(*bob);

    std::cout << *bob->get_brain() << std::endl;
    std::cout << *kelly->get_brain() << std::endl;

    bob->makeSound();

    delete bob;//should not create a leak
    delete rob;

    const Animal* test = new Animal;//  Should not compile.

    const Animal*   animals[10];
    int i;
    for (i = 0 ; i < 5 ; ++i)
        animals[i] = new Dog;
    for (i = 5 ; i < 10 ; ++i)
        animals[i] = new Cat;
    for (i = 0 ; i < 10 ; ++i)
        delete animals[i];
    system("leaks animals");
    return (0);
}