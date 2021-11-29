#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
class ICharacter;

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

#endif