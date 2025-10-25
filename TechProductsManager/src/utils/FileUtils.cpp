#include "FileUtils.h"
#include <fstream>
#include <sstream>

std::vector<Product> FileUtils::loadProducts(const std::string &filename)
{
    std::vector<Product> products;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        return products;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, category, region;
        double price;
        
        std::getline(ss, name, '|');
        std::getline(ss, category, '|');
        ss >> price;
        ss.ignore();
        std::getline(ss, region);
        
        if (!name.empty() && !category.empty() && !region.empty()) {
            products.emplace_back(name, category, price, region);
        }
    }
    
    file.close();
    return products;
}

void FileUtils::saveProducts(const std::string &filename, const std::vector<Product> &products)
{
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        return;
    }
    
    for (const auto &product : products) {
        file << product.getName() << "|" 
             << product.getCategory() << "|" 
             << product.getPrice() << "|" 
             << product.getRegion() << "\n";
    }
    
    file.close();
}