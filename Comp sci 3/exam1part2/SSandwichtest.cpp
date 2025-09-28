#include "SSandwich.h"
#include <iostream>
#include <stdio.h>


int main(int argc, char* argv[]) 
{
    // Create a regular sandwich with white bread and wrap format
    SloppySandwich sandwich;

    // Add contents to the sandwich
    sandwich + "Tomato" + "AmericanCheese" + "Ham";

    std::cout << "Size: " << static_cast<int>(sandwich.getSize()) << std::endl;
    std::cout << "Bread Type: " << static_cast<int>(sandwich.getBreadType()) << std::endl;
    std::cout << "Bread Format: " << static_cast<int>(sandwich.getBreadFormat()) << std::endl;

    return 0;
}
