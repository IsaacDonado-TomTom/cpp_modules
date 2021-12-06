#include <Convert.hpp>

Convert::Convert()
{
    return ;
}

Convert::Convert(const std::string& input) : _input(input)
{
    
    this->getType();
    this->_fail = false;
    return ;
}

Convert::~Convert()
{
    return ;
}

Convert::Convert(const Convert& src)
{
    (void)src;
    return ;
}

Convert&    Convert::operator=(const Convert &rhs)
{
    (void)rhs;
    return (const_cast<Convert&>(rhs));
}

bool    Convert::isInt(const std::string& str)
{
    for (size_t i = 0 ; i < str.length(); i++)
    {
        if (str[0] == '-')
            continue;
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}

bool    Convert::isFloat(const std::string& str)
{
    bool dot = false;
    bool res = false;
    size_t  i = 0;
    while (i < str.length())
    {
        if (str[i] == '.' && dot == false)
        {
            res = true;
            dot = true;
            i++;
        }
        else if (isdigit(str[i]))
            i++;
        else
        {
            if (i == str.length() - 1 && str[i] == 'f')
                i++;
            else
                return (false);
        }
    }
    return (res);
}

bool    Convert::isDouble(const std::string& str)
{
    bool dot = false;
    bool res = false;
    size_t  i = 0;
    while (i < str.length())
    {
        if (str[i] == '.' && dot == false)
        {
            res = true;
            dot = true;
            i++;
        }
        else if (str[i] == 'f')
        {
            res = false;
            break ; 
        }
        else if (isdigit(str[i]))
            i++;
        else
            return (false);
    }
    return (res);
}

void    Convert::getType()
{
    std::string str = this->_input;
    if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff" || str == "nan" || str == "nanf")
        {this->_type = OTHER; return ;}
    if (str.length() == 1 && !isdigit(str[0]))
        {this->_type = CHAR; return ;}
    if (this->isInt(str) == true)
        {this->_type = INT; return ;}
    if (this->isFloat(str) == true)
        {this->_type = FLOAT; return ;}
    if (this->isDouble(str) == true)
        {this->_type = DOUBLE; return ;}
    this->_type = ERROR; return ;
}

int    Convert::getType(int x) const
{
    
    (void)x;
    return (this->_type);
}

std::string Convert::getInput() const
{
    return (this->_input);
}

void    Convert::setValue()
{
    if (this->_type == CHAR)
        this->_valueChar = this->_input[0];
    else if (this->_type == INT)
    {
        try
            {this->_valueInt = std::stoi(this->_input, NULL, 10);}
        catch (std::exception& e)
            {this->_fail = true;}
    }
    else if (this->_type == FLOAT)
    {
        try
            {this->_valueFloat = std::stof(this->_input);}
        catch (std::exception& e)
            {this->_fail = true;}
    }
    else if (this->_type == DOUBLE)
    {
        try
            {this->_valueDouble = std::stod(this->_input);}
        catch (std::exception& e)
            {this->_fail = true;}
    }
}