#pragma once
#ifndef PRODUCTCATEGORY_H
#define PRODUCTCATEGORY_H

#include <cstdint>
#include<iostream>

enum class ProductCategory : uint16_t
{
    CLOTHING = 1,
    FOOD,
    TECHNOLOGY,
    FURNITURE,
    SPORTS,
    BOOKS
};

std::string ProductCategoryToString(ProductCategory category);
void SelectProductCategory(ProductCategory &category);

ProductCategory NumberToCategory(uint16_t number);
uint16_t CategoryToNumber(ProductCategory category);


#endif // !PRODUCTCATEGORY_H