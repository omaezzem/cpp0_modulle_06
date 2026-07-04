#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <value>" << std::endl;
        return 1;
    }
    try
    {
        ScalarConverter converter;
        converter.convert(argv[1]);
    }
    catch (const ScalarConverter::imposibleconversion &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return 1;
    }
    return 0;
}