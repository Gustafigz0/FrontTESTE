#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
public:
    Product();
    Product(const std::string &name, const std::string &category, double price, const std::string &region);
    
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    std::string getRegion() const;
    
    void setName(const std::string &name);
    void setCategory(const std::string &category);
    void setPrice(double price);
    void setRegion(const std::string &region);
    
private:
    std::string name;
    std::string category;
    double price;
    std::string region;
};

#endif // PRODUCT_H