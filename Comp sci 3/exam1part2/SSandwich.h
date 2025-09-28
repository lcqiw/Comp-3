
#ifndef SSANDWICH_H
#define SSANDWICH_H

#include <vector>
#include <string>
#include "SSandwichtest.cpp"

enum Size 
{ 
    Regular,
    Glutton
 };
enum BreadType 
{ 
    White, 
    Wheat, 
    Rye 
};
enum BreadFormat 
{ 
    Wrap, 
    Sub, 
    Sliced 
};


class SloppySandwich 
{
private:
    Size size;
    BreadType breadType;
    BreadFormat breadFormat;
    std::vector<std::string> contentsList;

public:
    SloppySandwich();

    SloppySandwich(Size size, BreadType breadType, BreadFormat breadFormat);

    Size getSize() const;
    BreadType getBreadType() const;
    BreadFormat getBreadFormat() const;

    void setSize(Size size);
    void setBreadType(BreadType breadType);
    void setBreadFormat(BreadFormat breadFormat);

    SloppySandwich& operator+(const std::string& content);
};

#endif 
