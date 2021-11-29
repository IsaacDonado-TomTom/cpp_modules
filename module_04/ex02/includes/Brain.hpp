#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
public:
    Brain();
    ~Brain();
    Brain(const Brain& src);

    Brain&  operator=(const Brain& rhs);
    void    setIdea(int i, std::string idea);
    //friend std::ostream& operator<<(std::ostream& output, const Brain& source);
protected:
    std::string ideas[100];
};

#endif