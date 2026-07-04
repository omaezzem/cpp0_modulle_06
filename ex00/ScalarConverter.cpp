#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
bool ScalarConverter::ischar(const std::string &str)
{
    if (str.length() == 1 && !std::isdigit(str[0]))
        return true;
    return false;
}

bool ScalarConverter::isint(const std::string &str)
{
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-')
    {
        if (str.length() == 1)
            return false;
        i = 1;
    }
    while(i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool is_point_f(const std::string &str)
{
    size_t point_count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '.')
            point_count++;
    }
    if (point_count == 1 && str[str.length() - 1] == 'f')
        return true;
    return false;
}
bool is_point(const std::string &str)
{
    size_t point_count = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '.')
            point_count++;
    }
    if (point_count == 1 && str[str.length() - 1] != 'f')
        return true;
    return false;
}

bool ScalarConverter::is_pseudo_f(const std::string &str)
{
    return (str == "nanf" ||
            str == "+inff" ||
            str == "-inff");
}

bool ScalarConverter::is_pseudo(const std::string &str)
{
    return (str == "nan" ||
            str == "+inf" ||
            str == "-inf");
}

bool ScalarConverter::isfloat(const std::string &str)
{
    if (!is_point_f(str))
        return false;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length() - 1) // ignore final 'f'
    {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return false;
        i++;
    }

    return true;
}

bool ScalarConverter::isdouble(const std::string &str)
{
    if (!is_point(str))
        return false;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return false;
        i++;
    }
    return true;
}

void ScalarConverter::convertchar(const std::string &str)
{
    if (!ischar(str))
        throw ScalarConverter::imposibleconversion();

    char c = str[0];

    if (c >= 32 && c <= 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertint(const std::string &str)
{
    if (!isint(str))
        throw ScalarConverter::imposibleconversion();

    int i;
    std::stringstream ss(str);
    ss >> i;

    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else if (i >= 0 && i <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    std::cout << "int: " << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertfloat(const std::string &str)
{
    if (!isfloat(str))
        throw ScalarConverter::imposibleconversion();

    float f;
    std::stringstream ss(str);
    ss >> f;

    if (static_cast<int>(f) >= 32 && static_cast<int>(f) <= 126)
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else if (static_cast<int>(f) >= 0 && static_cast<int>(f) <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertdouble(const std::string &str)
{
    if (!isdouble(str))
        throw ScalarConverter::imposibleconversion();

    double d;
    std::stringstream ss(str);
    ss >> d;

    if (static_cast<int>(d) >= 32 && static_cast<int>(d) <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else if (static_cast<int>(d) >= 0 && static_cast<int>(d) <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
void ScalarConverter::convertPseudoFloat(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << std::endl;

    if (str == "nanf")
        std::cout << "double: nan" << std::endl;
    else if (str == "+inff")
        std::cout << "double: +inf" << std::endl;
    else
        std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::convertPseudoDouble(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    if (is_pseudo_f(str))
    {
        convertPseudoFloat(str);
        return;
    }

    if (is_pseudo(str))
    {
        convertPseudoDouble(str);
        return;
    }

    if (ischar(str))
        convertchar(str);
    else if (isint(str))
        convertint(str);
    else if (isfloat(str))
        convertfloat(str);
    else if (isdouble(str))
        convertdouble(str);
    else
        throw ScalarConverter::imposibleconversion();
}



