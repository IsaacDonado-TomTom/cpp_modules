#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

# define ERROR 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define OTHER 5

class Convert
{
    private:
        const std::string   _input;
        int                 _type;
        char                _valueChar;
        int                 _valueInt;
        float               _valueFloat;
        double              _valueDouble;
        bool                _fail;

        Convert();
        Convert(const Convert& src);
        Convert&    operator=(const Convert& rhs);
    public:
        Convert(const std::string& input);
        ~Convert();

        void        getType();
        int         getType(int x) const;
        std::string getInput() const;
        void        setValue();
        bool        isInt(const std::string& str);
        bool        isFloat(const std::string& str);
        bool        isDouble(const std::string& str);
};

#endif