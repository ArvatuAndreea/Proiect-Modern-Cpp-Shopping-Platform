#pragma once
#ifndef SEARCHBAR_H
#define SEARCHBAR_H
#include <iostream>
#include <vector>
#include <algorithm>
//#include "Product.h"
#include "ProductCategory.h"
class Product;

class Search_Bar
{
private:
	std::vector<Product> s_listOfProducts;
	ProductCategory s_listOfCategories;

	Product LowerPrice(Product, Product);
	Product HigherPrice(Product, Product);
public:
	Search_Bar(std::vector<Product>, ProductCategory);
	Search_Bar() = default;
	Search_Bar(Search_Bar&&);
	Search_Bar& operator= (Search_Bar&&) = default;
	std::vector<Product> GetListOfProducts() const noexcept;
	ProductCategory GetListOfCategories() const noexcept;

	void SearchByNameOfProduct(std::string name_of_product);
	void SearchByNameOfCategory(std::string name_of_category);

	void FilterProductsByLowerPrice();
	void FilterProductByHigherPrice();
	void FilterProductsByRating();

	friend std::ostream& operator<<(std::ostream& out, const Search_Bar&);

};
#endif // !SEARCHBAR_H

