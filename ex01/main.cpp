#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.id = 42;
    data.name = "Omar";

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << raw << std::endl;
    std::cout << "Restored pointer : " << restored << std::endl;

    if (ptr == restored)
        std::cout << "Pointers are equal" << std::endl;
    else
        std::cout << "Pointers are different" << std::endl;

    std::cout << restored->id << std::endl;
    std::cout << restored->name << std::endl;
}
