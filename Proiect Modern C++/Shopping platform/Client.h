#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
//#include "Comanda.h"
#include "Wishlist.h"
//#include "Product.h"
//#include "GiftVoucher.h"

class Comanda;
class Wishlist;
class Product;
class GiftVoucher;


class Client
{
private:
	std::string c_name;
	std::string c_phone;
	std::string c_address;
	std::string c_email;
	std::string c_password;
	std::string c_creditCard;
	std::vector<Comanda> c_order_history;
	Wishlist c_wishlist;
	std::vector<Product> c_myRatings;
	std::vector<GiftVoucher> c_myVouchers;
	std::vector<Product> c_myReturnedProducts;
	int numarMinimCaractereParola = 8;
public:
	std::string GetName() const noexcept;
	std::string GetPhone() const noexcept;
	std::string GetAddress() const noexcept;
	std::string GetEmail() const noexcept;
	std::string GetPassword() const noexcept;
	std::string GetCreditCard() const noexcept;
	Wishlist GetWishlist() const noexcept;

	std::vector<Product> GetRatings() const noexcept;
	std::vector<GiftVoucher>GetVouchers() const noexcept;
	std::vector<Product>GetReturnedProducts() const noexcept;

	Client(std::string, std::string, std::string, std::string, std::string, std::string, std::vector<Comanda>, Wishlist, std::vector<Product>, std::vector<GiftVoucher>, std::vector<Product>);
	Client();
	Client(Client const& other);
	Client(Client&& that) noexcept;

	std::vector<Comanda> GetOrderHistory() const noexcept;
	void UpdateOrderHistory(Comanda new_command);

	friend std::istream& operator>> (std::istream& in, Client& client);
	friend std::ostream& operator<< (std::ostream& out, Client& client);
	friend void swap(Client& lhs, Client& rhs) noexcept;
	Client& operator=(Client const& other);
	Client& operator=(Client&& that) noexcept;

	void ChangeName(std::string& newName);
	void ChangePassword(std::string& newPassword);
	void ChangeAddress(std::string& newAdress);
	void ChangePhone(std::string& newPhone);
	void ChangeEmail(std::string& newEmail);
	void ChangeCreditCard(std::string& newCreditCard);
	void AddVoucher(std::vector<GiftVoucher>c_myVouchers, GiftVoucher newVoucher);
	void LoginAccount(Client& client);
	void CreatenewAccount(Client& client);
	void ForgotMyPassword(std::string& newPassword);
};

#endif // !CLIENT_H