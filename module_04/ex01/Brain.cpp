#include <Brain.hpp>

// Brain class functions.

Brain::Brain()
{
    std::cout << "Brain created." << std::endl; 
    return ;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed." << std::endl;
    return ;
}

Brain::Brain(const Brain& src)
{
    int i;
    for (i=0; i < 100 ; ++i)
    {
        this->ideas[i] = src.ideas[i];
    }
    std::cout << "Brain copy constructor." << std::endl;
}

Brain&  Brain::operator=(const Brain& rhs)
{
    int i;
    if (this != &rhs)
    {
        for (i=0; i < 100 ; ++i)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    std::cout << "Brain assignment overload called." << std::endl;
    return *this;
}

void    Brain::setIdea(int i, std::string idea)
{
    i -= 1;
    if (i < 0 || i > 99)
        std::cout << "Unable to set idea." << std::endl;
    this->ideas[i] = idea;
    return ;
}

//std::ostream& operator<<(std::ostream& output, const Brain& source)
//{
//    output << "Ideas: [ ";
//    int i;
//    for (i = 0 ; i < 100 ; ++i)
//    {
//        if (source.ideas[i].length() > 0)
//            output << "Idea[" << i << "]: " << source.ideas[i] << ", ";
//    }
//    output << " ]" << std::endl;
//    return output;
//}
