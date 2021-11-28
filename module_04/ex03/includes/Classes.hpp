#ifndef CLASSES_HPP
# define CLASSES_HPP
# include <iostream>
# include <ostream>

class AMateria;
////////////////////////////////////////////////////////////////
//              IMateriaSource | Materia Source               //
////////////////////////////////////////////////////////////////
class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource {
public:
    virtual ~MateriaSource();
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    MateriaSource&  operator=(const MateriaSource& rhs);

    virtual void    learnMateria(AMateria* materia);
    virtual AMateria*   createMateria(const std::string& type);
private:
    AMateria*   _materia[4];
};

////////////////////////////////////////////////////////////////
//                  ICharacter / Character                    //
////////////////////////////////////////////////////////////////
class ICharacter {
public:
    virtual                     ~ICharacter() {};
    virtual const std::string&  getName() const = 0;
    virtual void                equip(AMateria* m) = 0;
    virtual void                unequip(int idx) = 0;
    virtual void                use(int idx, ICharacter& target) = 0;
};
/////////////////
//  Character  //
/////////////////
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

/////////////////////////////////////////////////////////////
//                    AMateria | Ice | Cure                //
/////////////////////////////////////////////////////////////
////////////////
//  AMateria  //
////////////////
class AMateria {
public:
    AMateria(const std::string& type);
    AMateria(const AMateria& src);
    virtual ~AMateria();

    AMateria&           operator=(const AMateria& rhs);
    const std::string&  getType() const;
    virtual AMateria*   clone() const = 0;
    virtual void        use(ICharacter& target);
protected:
    AMateria();
    std::string _type;
};
std::ostream&   operator<<(std::ostream& output, AMateria& materia);
///////////
//  Ice  //
///////////
class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice& src);
    virtual ~Ice();

    Ice&                 operator=(const Ice& rhs);
    virtual AMateria*   clone() const;
    virtual void    use(ICharacter& target);
};
////////////
//  Cure  //
////////////
class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure& src);
    virtual ~Cure();

    Cure&               operator=(const Cure& rhs);
    virtual AMateria*   clone() const;
    virtual void    use(ICharacter& target);
};



#endif