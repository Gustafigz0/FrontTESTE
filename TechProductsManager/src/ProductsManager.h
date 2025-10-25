#ifndef PRODUCTSMANAGER_H
#define PRODUCTSMANAGER_H

#include "Product.h"
#include <vector>
#include <string>

class ProductsManager
{
public:
    ProductsManager();
    ~ProductsManager();
    
    void addProduct(const Product &product);
    void removeProduct(const std::string &name);
    void updateProduct(const std::string &name, const Product &newProduct);
    
    std::vector<Product> getAllProducts() const;
    std::vector<Product> getProductsByRegion(const std::string &region) const;
    std::vector<Product> getProductsByCategory(const std::string &category) const;
    
    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
    
private:
    std::vector<Product> products;
};

#endif // PRODUCTSMANAGER_H