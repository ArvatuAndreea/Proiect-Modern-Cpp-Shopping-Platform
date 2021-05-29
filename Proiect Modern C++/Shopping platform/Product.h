#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "Distributor.h"
#include "ProductCategory.h"
#include <vector>
#include <tuple>

class Distributor;


class Product
{
public:
    Product();
    Product(std::string name, ProductCategory productCategory, Distributor distribuitor, std::string description, std::vector<std::tuple<std::string, unsigned int>>, float price, float rating, double stock, int discount);
    Product(Product const& other);
    Product(Product&& that) noexcept;


    std::string GetName() const noexcept;
    ProductCategory GetCategory() const noexcept;
    Distributor GetDistributor() const noexcept;
    std::string GetDescription() const noexcept;
    float GetPrice() const noexcept;
    unsigned int GetAverageReview();
    std::vector<std::tuple<std::string, unsigned int>> GetReviewsList() noexcept;

    float GetRating() const noexcept;
    double GetStock()const noexcept;
    int GetDiscount() const noexcept;
    float GetDiscountedPrice() const;
    bool IsInStock() const;
    void EditProductName(std::string& newName);
    void EditProductDescription(std::string& newDescription);
    void EditProductCategory(ProductCategory& newCategory);
    void EditProductDistributor(Distributor& newDistributor);
    void EditProductPrice(float newPrice);
    void RetrievalStock(double newstock);

    friend std::istream& operator>>(std::istream& fin, Product&);
    friend std::ostream& operator<<(std::ostream& out, const Product&);
    friend void swap(Product& lhs, Product& rhs) noexcept;
    Product& operator=(Product const& other);
    Product& operator=(Product&& that) noexcept;

private:
    double p_stock;
    std::string p_name;
    ProductCategory p_productCategory;
    Distributor p_distributor;
    std::string p_productDescription;
    std::vector<std::tuple<std::string, unsigned int>> p_reviewsList;
    float p_price;
    float p_rating;
    int p_discount;
};
#endif // !PRODUCT_H