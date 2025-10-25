#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "Product.h"
#include <vector>
#include <string>

class FileUtils
{
public:
    static std::vector<Product> loadProducts(const std::string &filename);
    static void saveProducts(const std::string &filename, const std::vector<Product> &products);
};

#endif // FILEUTILS_H