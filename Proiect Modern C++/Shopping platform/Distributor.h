#pragma once
#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H


#include <iostream>
#include <vector>
//#include "Product.h"
#include "ProductCategory.h"
class Product;

class Distributor
{
private:
	std::string d_name;
	std::string d_phone;
	std::string d_address;
	std::string d_email;
	std::string d_uniqueRegistrationCode;
	std::string d_IBAN;
	std::string d_bank;
	std::vector<Product> d_ourProducts;

public:
	Distributor(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::vector<Product>);
	Distributor() = default;
	Distributor(Distributor&&) noexcept;
	Distributor operator=(Distributor const& other);
	Distributor(Distributor const& other);


	std::string getName() const noexcept;
	std::string getPhone() const noexcept;
	std::string getAddress() const noexcept;
	std::string getEmail()const noexcept;
	std::string getUniqueRegistrationCode()const noexcept;
	std::string getIBAN()const noexcept;
	std::string getBank()const noexcept;
	std::vector<Product> getProducts() const noexcept;

	friend std::istream& operator>> (std::istream& in, Distributor& distributor);
	friend std::ostream& operator<< (std::ostream& out, Distributor& distributor);

};
#endif // !DISTRIBUTOR_H