#include <Convert.hpp>

Convert::Convert()
{
    return ;
}

Convert::Convert(const std::string& input) : _input(input)
{
    
    this->getType();
    this->_failDouble = false;
    this->_failFloat = false;
    this->_failInt = false;
    this->_failChar = false;
    return ;
}

Convert::~Convert()
{
    exit (0);
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
    {
        this->_valueChar = this->_input[0];
        this->_valueFloat = static_cast<float>(this->_input[0]);
        this->_valueDouble = static_cast<double>(this->_input[0]);
        this->_valueInt = static_cast<int>(this->_input[0]);
    }
    else
    {
        try
        {
            this->_valueDouble = std::stod(this->_input);
        }
        catch(const std::exception& e)
        {
            std::cerr << "ERROR: invalid input." << std::endl;
            this->~Convert();
        }

        try
        {
            this->_valueFloat = std::stof(this->_input);
        }
        catch(const std::exception& e)
        {
            this->_failFloat = true;
        }

        try
        {
            this->_valueInt = std::stoi(this->_input, NULL, 10);
            if (this->_valueDouble - _valueInt >= 0.5 && this->_valueInt < std::numeric_limits<int>::max())
                this->_valueInt = this->_valueInt + 1;
            if (this->_valueDouble - _valueInt >= 0.5 && this->_valueInt == std::numeric_limits<int>::max())
                this->_failInt = true;
        }
        catch (std::exception& e)
        {
            this->_failInt = true;
        }

        if (this->_failInt == true)
            this->_failChar = true;
        else if (this->_valueInt >= std::numeric_limits<char>::min() && this->_valueInt <= std::numeric_limits<char>::max())
            this->_valueChar = static_cast<char>(this->_valueInt);
        else
            this->_failChar = true;
    }
    
}


std::ostream&   operator<<(std::ostream& output, Convert& converter)
{
    if (isprint(converter._valueChar))
        output << "char: '" << converter._valueChar << "'" << std::endl;
    else if (isnan(converter._valueFloat) || converter._failChar == true)
        output << "char: impossible" << std::endl;
    else
        output << "char: Non displayable" <<std::endl;

    if (isnan(converter._valueFloat) || converter._failInt == true)
        output << "int: impossible" << std::endl;
    else
        output << "int: " << converter._valueInt  << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    if (converter._failFloat == true)
        output << "float: impossible" << std::endl;
    else
        output << "float: " << converter._valueFloat << "f" << std::endl;
    output << "double: " << converter._valueDouble << std::endl;
    return (output);
}

