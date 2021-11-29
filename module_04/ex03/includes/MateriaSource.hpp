#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <IMateriaSource.hpp>

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

#endif