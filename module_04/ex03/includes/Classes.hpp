#ifndef CLASSES_HPP
# define CLASSES_HPP
# include <iostream>

class AMateria;

class ICharacter {
public:
    virtual ~ICharacter() = 0;
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class AMateria {
public:
    AMateria(std::string& type);
    AMateria(const AMateria& src);
    virtual ~AMateria();

    AMateria&   operator=(const AMateria& rhs);
    const std::string&  getType() const;
    virtual AMateria*   clone() const = 0;
    virtual void        use(ICharacter& target);
protected:
    AMateria();
    std::string type;
};

class Ice : public AMateria {
public:
    Ice(std::string& type);
    Ice(const Ice& src);
    virtual ~Ice();

    Ice&            operator=(const Ice& rhs);
    virtual Ice*    clone() const;
    virtual void    use(ICharacter& target);
protected:
    Ice();
};

class Cure : public AMateria {
public:
    Cure(std::string& type);
    Cure(const Cure& src);
    virtual ~Cure();

    Ice&    operator=(const Ice& rhs);
    virtual Cure*   close() const;
    virtual void    use(ICharacter& target);
protected:
    Cure();
};

#endif