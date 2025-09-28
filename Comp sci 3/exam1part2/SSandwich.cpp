#include "SSandwich.h"
#include "SSandwichtest.cpp"

SloppySandwich::SloppySandwich() 
    : size(Size::Regular), breadType(BreadType::White), breadFormat(BreadFormat::Wrap) 
    {
}

SloppySandwich::SloppySandwich(Size size, BreadType breadType, BreadFormat breadFormat) 
    : size(size), breadType(breadType), breadFormat(breadFormat) 
    {
}

Size SloppySandwich::getSize() 
const {
    return size;
}

BreadType SloppySandwich::getBreadType()
const{
    return breadType;
}

BreadFormat SloppySandwich::getBreadFormat() 
const{

    return breadFormat;
}

void SloppySandwich::setSize(Size newSize) 
{
    size = newSize;
}

void SloppySandwich::setBreadType(BreadType newBreadType)
 {
    breadType = newBreadType;
}

void SloppySandwich::setBreadFormat(BreadFormat newBreadFormat) 
{
    breadFormat = newBreadFormat;
}

SloppySandwich& SloppySandwich::operator+(const std::string& content) 
{
    contentsList.push_back(content);
    return *this; 
}
