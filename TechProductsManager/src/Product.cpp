#include "Product.h"

Product::Product()
    : name(""), category(""), price(0.0), region("")
{
}

Product::Product(const std::string &name, const std::string &category, double price, const std::string &region)
    : name(name), category(category), price(price), region(region)
{
}

std::string Product::getName() const
{
    return name;
}

std::string Product::getCategory() const
{
    return category;
}

double Product::getPrice() const
{
    return price;
}

std::string Product::getRegion() const
{
    return region;
}

void Product::setName(const std::string &name)
{
    this->name = name;
}

void Product::setCategory(const std::string &category)
{
    this->category = category;
}

void Product::setPrice(double price)
{
    this->price = price;
}

void Product::setRegion(const std::string &region)
{
    this->region = region;
}