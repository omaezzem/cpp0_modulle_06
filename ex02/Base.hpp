#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <typeinfo> 

class Base
{
    public:
        virtual ~Base() {}

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif
