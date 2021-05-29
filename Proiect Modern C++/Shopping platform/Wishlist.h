#pragma once
#ifndef WISHLIST_H
#define WISHLIST_H

#include <iostream>
#include "Client.h"
#include "Product.h"
#include "ProductCategory.h"
#include <vector>
#include <tuple>

class Client;
class Product;

class Wishlist
{
public:
    Wishlist() = default;
    Wishlist(Wishlist const& other);
    Wishlist(Wishlist&& that);
    Wishlist& operator= (Wishlist&&) = default;
    Wishlist(Client& client, std::vector<std::tuple<Product, unsigned int>>& productlist, float totalPrice);

    Client GetClient() const noexcept;
    std::vector<std::tuple<Product, unsigned int>> GetProductList() const noexcept;
    std::vector<std::tuple<Product, unsigned int>> GetProductListByCategory(ProductCategory category) const noexcept;
    std::vector<std::tuple<Product, unsigned int>> GetProductListPriceLower(float price) const noexcept;
    std::vector<std::tuple<Product, unsigned int>> GetProductListPriceHigher(float price) const noexcept;
    std::vector<std::tuple<Product, unsigned int>> GetProductListRatingHigher(float rating) const noexcept;
    float GetTotalPrice();
    float GetPriceForCategory(ProductCategory category) const noexcept;
    void AddProduct(Product& product, unsigned int pieces);
    void RemoveProduct(Product prod);
    void RemoveProductsFromCategory(ProductCategory category);
    void SendToCart(Product prod);
    void EmptyWishlish();
    //friend std::istream& operator>>(std::istream& fin, Wishlist&);
    friend std::ostream& operator<<(std::ostream& out, const Wishlist&);

private:
    Client w_client;
    std::vector<std::tuple<Product, unsigned int>> w_productList;
    float w_totalPrice;
    void RefreshWishlistPrice();
};

#endif // !WISHLIST_H
