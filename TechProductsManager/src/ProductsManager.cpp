#include "ProductsManager.h"
#include "utils/FileUtils.h"
#include <algorithm>

ProductsManager::ProductsManager()
{
    loadFromFile("resources/products.txt");
}

ProductsManager::~ProductsManager()
{
    saveToFile("resources/products.txt");
}

void ProductsManager::addProduct(const Product &product)
{
    products.push_back(product);
}

void ProductsManager::removeProduct(const std::string &name)
{
    products.erase(
        std::remove_if(products.begin(), products.end(),
            [&name](const Product &p) { return p.getName() == name; }),
        products.end()
    );
}

void ProductsManager::updateProduct(const std::string &name, const Product &newProduct)
{
    for (auto &product : products) {
        if (product.getName() == name) {
            product = newProduct;
            break;
        }
    }
}

std::vector<Product> ProductsManager::getAllProducts() const
{
    return products;
}

std::vector<Product> ProductsManager::getProductsByRegion(const std::string &region) const
{
    std::vector<Product> filtered;
    for (const auto &product : products) {
        if (product.getRegion() == region) {
            filtered.push_back(product);
        }
    }
    return filtered;
}

std::vector<Product> ProductsManager::getProductsByCategory(const std::string &category) const
{
    std::vector<Product> filtered;
    for (const auto &product : products) {
        if (product.getCategory() == category) {
            filtered.push_back(product);
        }
    }
    return filtered;
}

void ProductsManager::saveToFile(const std::string &filename)
{
    FileUtils::saveProducts(filename, products);
}

void ProductsManager::loadFromFile(const std::string &filename)
{
    products = FileUtils::loadProducts(filename);
}