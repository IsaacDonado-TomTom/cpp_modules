#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>
#include <Character.hpp>
 
 void   main_test()
 {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
 }

 void   materia_not_yet_learned()
 {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    // Does nothing after this.
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());

    // Try to create Cure, not yet learned.
    AMateria* materia = src->createMateria("cure");
    if (materia == NULL)
        std::cout << "Not learned yet" << std::endl;

    // Now it will work, Ice has been learned.
    materia = src->createMateria("ice");
    if (materia == NULL)
        std::cout << "Not learned yet" << std::endl;
    else
        std::cout << "Success. materia created" << std::endl;
    
    delete src; delete materia;
 }

 void   unequiped_materias()
 {
    IMateriaSource* src = new MateriaSource();
    Character* bill = new Character("Bill");

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    // Bill will fill up all materia inventory slots
    bill->equip(src->createMateria("ice"));
    bill->equip(src->createMateria("ice"));
    bill->equip(src->createMateria("ice"));
    bill->equip(src->createMateria("cure"));

    // List materias
    bill->list_materias();

    // Add some more.. nothing will happen
    bill->equip(src->createMateria("cure"));
    bill->equip(src->createMateria("cure"));

    //List again to show nothing happened.
    bill->list_materias();

    // Unequip slot 0 and 2
    bill->unequip(0);
    bill->unequip(2);
    // List again.
    bill->list_materias();

    // Add two more to fill slots again
    bill->equip(src->createMateria("ice"));
    bill->equip(src->createMateria("cure"));
    // List again.
    bill->list_materias();

    delete bill; delete src;
 }

 void   unequip_does_not_delete()
 {
    Ice* materia = new Ice();

    Character*  bob = new Character("Bob");
    // Only fills one slot, materias dont have to be unique, but you can't equip the same one.
    bob->equip(materia);
    bob->equip(materia);
    bob->equip(materia);

    bob->list_materias();

    bob->unequip(0);

    if (materia != NULL)
        std::cout << "Materia still exists, it was unequipped but still exists" << std::endl;

    // Let's equip it again so that it's destroyed when bob is deleted.
    bob->equip(materia);

    delete bob;
 }

 void   assign_and_copy_characters()
 {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character* one = new Character("one");
    Character* two = new Character("two");
    Character* three = new Character("three");
    Character* four = new Character("four");

    one->equip(src->createMateria("ice"));
    one->equip(src->createMateria("ice"));
    one->equip(src->createMateria("cure"));
    one->equip(src->createMateria("cure"));

    // List one and two's materias
    one->list_materias();
    two->list_materias();

    Character* temp = three;
    three = one;
    // list three should now be one
    if (three == one)
        std::cout << "three and one are equal" << std::endl;

    // recover three so memory isn't lost and one isn't double deleted.
    three = temp;

    Character* temp_two = new Character(*one);
    // Temp_two is now a copy of one, but not the same
    temp_two->list_materias();
    if (temp_two != one)
        std::cout << "three and one are NOT equal" << std::endl;


    delete src; delete one; delete two; delete three; delete four; delete temp_two;
 }

 void   using_materias()
 {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character* one = new Character("one");
    Character* two = new Character("two");

    one->equip(src->createMateria("ice"));
    one->equip(src->createMateria("cure"));

    one->use(0, *two);
    one->use(1, *two);

    // won't work, nothing is in slot 2
    one->use(2, *two);

    // won't work, two has nothing
    two->use(0, *two);
    two->use(1, *two);
    two->use(2, *two);
    two->use(3, *two);

    // definately won't work, can't go beyond 3 or under 0 in slots.. only space for 4
    one->use(-1, *two);
    one->use(4, *two);

    delete src; delete one; delete two;
 }

int main(void)
{
    main_test();

    materia_not_yet_learned();

    unequiped_materias();

    unequip_does_not_delete();

    assign_and_copy_characters();

    using_materias();

    return (0);
}