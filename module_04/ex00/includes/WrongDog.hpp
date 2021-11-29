#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include <WrongAnimal.hpp>

class WrongDog : public WrongAnimal {
public:
    WrongDog();
    WrongDog(const WrongDog& src);
    ~WrongDog();

    WrongDog& operator=(const WrongDog& rhs);
    const std::string& get_type() const;
    void    makeSound() const;
};

#endif