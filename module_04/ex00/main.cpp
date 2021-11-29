#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongDog.hpp>
#include <WrongCat.hpp>

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->get_type() << " " << std::endl;
    std::cout << i->get_type() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta; delete j; delete i;

    const WrongAnimal* meta_two = new WrongAnimal();
    const WrongAnimal* j_two = new WrongDog();
    const WrongAnimal* i_two = new WrongCat();

    std::cout << j_two->get_type() << " " << std::endl;
    std::cout << i_two->get_type() << " " << std::endl;
    i_two->makeSound();
    j_two->makeSound();
    meta_two->makeSound();
    delete meta_two;delete j_two;delete i_two;
    return (0);
}