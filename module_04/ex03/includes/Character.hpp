#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <ICharacter.hpp>

class Character : public ICharacter {
public:
    Character(const std::string& name);
    virtual ~Character();
    Character(const Character& src);
    Character&                  operator=(const Character& rhs);

    virtual const std::string&  getName() const;
    virtual void                equip(AMateria* m);
    virtual void                unequip(int idx);
    virtual void                use(int idx, ICharacter& target);
    void    list_materias() const;
private:
    std::string _name;
    AMateria*   _inventory[4];
    Character();
};

#endif