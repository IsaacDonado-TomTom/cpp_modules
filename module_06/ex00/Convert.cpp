#include <Convert.hpp>

Convert::Convert()
{
    return ;
}

Convert::Convert(const std::string& input) : _input(input)
{
    
    this->_failDouble = false;
    this->_failFloat = false;
    this->_failInt = false;
    this->_failChar = false;
    this->error_num = 0;
    this->getType();
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

char    Convert::getChar(void) { return(this->_valueChar); }

int    Convert::getInt(void) { return(this->_valueInt); }

float    Convert::getFloat(void) { return(this->_valueFloat); }

double    Convert::getDouble(void) { return(this->_valueDouble); }

bool    Convert::isFail(const std::string& type)
{
    if (type == "int")
        return(this->_failInt);
    else if (type == "double")
        return(this->_failDouble);
    else if (type == "float")
        return(this->_failFloat);
    else if (type == "char")
        return(this->_failChar);
    else
        return false;
}

bool    Convert::isInt(const std::string& str)
{
    for (size_t i = 0 ; i < str.length(); i++)
    {
        if (str[0] == '-' && i == 0)
            continue;
        if (!isdigit(str[i]))
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
            {
                res = true;
                i++;
            }
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
    if (str.length() == 1 && !isdigit(str[0])&& str[0] >= std::numeric_limits<char>::min() && str[0] <= std::numeric_limits<char>::max())
        {this->_type = CHAR; return ;}
    if (this->isInt(str) == true)
        {this->_type = INT; return ;}
    if (this->isFloat(str) == true)
        {this->_type = FLOAT; return ;}
    if (this->isDouble(str) == true)
        {this->_type = DOUBLE; return ;}
    this->error_num = -1;
    this->_type = ERROR; return ;
}

std::string Convert::getInput() const
{
    return (this->_input);
}

void    Convert::setValue()
{
    double whole;
    double decimals;
    if (this->_type == CHAR)
    {
        this->_valueChar = static_cast<char>(this->_input[0]);
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
            this->error_num = -1;
            return ;
        }

        try
        {
            if ((this->_valueDouble > std::numeric_limits<float>::max() || this->_valueDouble < std::numeric_limits<float>::min()) && this->_type != OTHER)
                throw std::exception();
            else
                this->_valueFloat = static_cast<float>(this->_valueDouble);
        }
        catch(const std::exception& e)
        {
            this->_failFloat = true;
        }

        try
        {
            decimals = std::modf(this->_valueDouble, &whole);
            if (decimals >= 0.5)
                whole = whole + 1;
            if (whole > std::numeric_limits<int>::max() || whole < std::numeric_limits<int>::min())
                throw std::exception();
            this->_valueInt = static_cast<int>(whole);
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
    if (isprint(converter.getChar()) && converter.isFail("char") != true)
        output << "char: '" << converter.getChar() << "'" << std::endl;
    else if (isnan(converter.getFloat()) || converter.isFail("char") == true)
        output << "char: impossible" << std::endl;
    else
        output << "char: Non displayable" <<std::endl;

    if (isnan(converter.getFloat()) || converter.isFail("int") == true)
        output << "int: impossible" << std::endl;
    else
        output << "int: " << converter.getInt()  << std::endl;
    std::cout << std::fixed << std::setprecision(1);

    if (converter.isFail("float") == true)
        output << "float: impossible" << std::endl;
    else
        output << "float: " << converter.getFloat() << "f" << std::endl;
    output << "double: " << converter.getDouble() << std::endl;
    return (output);
}

