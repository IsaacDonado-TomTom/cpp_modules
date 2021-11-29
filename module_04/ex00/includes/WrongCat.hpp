#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& src);
    ~WrongCat();

    WrongCat& operator=(const WrongCat& rhs);
    const std::string& get_type() const;
    void    makeSound() const;
};

#endif