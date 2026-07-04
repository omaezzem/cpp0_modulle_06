#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <string>
#include <iostream>
#include <limits.h>
#include <iomanip>
#include <exception>
#include <sstream>

class ScalarConverter {
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        class imposibleconversion : public std::exception{};
        bool isint(const std::string &str);
        bool ischar(const std::string &str);
        bool isfloat(const std::string &str);
        bool isdouble(const std::string &str);
        bool is_pseudo(const std::string &str);
        bool is_pseudo_f(const std::string &str);
        void convertchar(const std::string &str);
        void convertint(const std::string &str);
        void convertfloat(const std::string &str);
        void convertdouble(const std::string &str);
        void convertPseudoFloat(const std::string &str);
        void convertPseudoDouble(const std::string &str);
        void convert(const std::string &str);
};

#endif