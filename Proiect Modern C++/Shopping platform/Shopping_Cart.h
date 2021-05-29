#pragma once
#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H


#include <iostream>
#include <vector>
#include <map>
#include "Product.h"
#include "Client.h"
#include "GiftVoucher.h"

class Product;
class Client;
class GiftVoucher;

class Shopping_Cart
{
private:
	Client s_client;
	std::vector<std::map<unsigned int, Product>> s_productList;
	Product s_product;
	GiftVoucher s_voucher;
	float s_TAXAtransport;
	float s_TOTAL;
	float s_priceFreeTransport = 200;
	int s_pieces;
	void CalculateTotal();
public:

	void FreeTransport();
	void AddToCart(Product prod);
	void AddToCart(Product prod, int s_pieces);
	float GetTotal();
	void RemoveProduct(Product prod);
	void RemoveProduct(Product& prod, int s_pieces);
	Client GetClient() const noexcept;
	GiftVoucher GetVoucher() const noexcept;
	float GetTaxaTransport() const noexcept;
	int GetPieces() const noexcept;
	Product GetProduct() const noexcept;
	std::vector<std::map<unsigned int, Product>> GetProductList() const noexcept;
	Shopping_Cart(Client& client, std::vector<std::map<unsigned int, Product>>& productlist, float totalPrice, float taxaTransport, Product product, GiftVoucher voucher, int pieces);
	Shopping_Cart() = default;
	Shopping_Cart(Shopping_Cart const& other);
	Shopping_Cart(Shopping_Cart&&);
	Shopping_Cart& operator= (Shopping_Cart&&) = default;
	friend std::istream& operator>>(std::istream& fin, Shopping_Cart&);
	friend std::ostream& operator<<(std::ostream& out, const Shopping_Cart&);


};
#endif // !SHOPPING_CART_H

