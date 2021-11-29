#include <MateriaSource.hpp>
#include <AMateria.hpp>
///////////////////////////////////////////////////////////////////
//                          MateriaSource                        //
///////////////////////////////////////////////////////////////////
MateriaSource::MateriaSource()
{
    int i;
    for (i = 0;i<4;++i)
        this->_materia[i] = NULL;
    //std::cout << "MateriaSource created." << std::endl;
}

MateriaSource::~MateriaSource()
{
    int i;
    for (i = 0;i<4;++i)
    {
        if (this->_materia[i] != NULL)
            delete this->_materia[i];
    }
    //std::cout << "MateriaSource deleted." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    //std::cout << "MateriaSource cloned." << std::endl;
    int i;
    for (i = 0;i<4;++i)
    {
        if (src._materia[i] != NULL)
            this->_materia[i] = src._materia[i]->clone();
        else
            this->_materia[i] = NULL;
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& rhs)
{
    //std::cout << "MateriaSource assigned." << std::endl;
    if (this != &rhs)
    {
        int i;
        for (i = 0; i < 4; ++i)
            delete this->_materia[i];
        for (i = 0; i < 4; ++i)
        {
            if (rhs._materia[i] != NULL)
                this->_materia[i] = rhs._materia[i]->clone();
            else
                this->_materia[i] = NULL;
        }
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* materia)
{
    if (materia != NULL)
    {
        int i;
        for (i = 0;i < 4;++i)
        {
            if (this->_materia[i] == NULL)
            {
                this->_materia[i] = materia->clone();
                return ;
            }
        }
    }
}

AMateria*   MateriaSource::createMateria(const std::string& type)
{
    int i;
    for (i = 0;i<4;++i)
    {
        if (this->_materia[i] != NULL)
        {
            if ((this->_materia[i]->getType()).compare(type) == 0)
                return (this->_materia[i]->clone());
        }
    }
    return NULL;
}
