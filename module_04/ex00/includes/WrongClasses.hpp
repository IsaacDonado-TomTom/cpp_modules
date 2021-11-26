#ifndef WRONGCLASSES_HPP
# define WRONGCLASSES_HPP
# include <iostream>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& src);
    ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& rhs);
    const std::string&  get_type() const;
    void    makeSound() const;
protected:
    std::string type;
};

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& src);
    ~WrongCat();

    WrongCat& operator=(const WrongCat& rhs);
    const std::string& get_type() const;
    void    makeSound() const;
};

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