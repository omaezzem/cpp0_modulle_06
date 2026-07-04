#include "Base.hpp"

Base *generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (std::bad_cast&) {}
}
