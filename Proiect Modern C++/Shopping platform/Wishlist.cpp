#include "Wishlist.h"
#include <tuple>
#include <iostream>

#include "Client.h"
#include "Product.h"


Wishlist::Wishlist(Wishlist const& other) :
	w_client(other.w_client), w_productList(other.w_productList), w_totalPrice(other.w_totalPrice)
{
}

Wishlist::Wishlist(Wishlist&& obj)
{
	*this = std::move(obj);
}

Wishlist::Wishlist(Client& client, std::vector<std::tuple<Product, unsigned int>>& productlist, float totalPrice) :
	w_client(client), w_productList(productlist), w_totalPrice(totalPrice)
{
}

Client Wishlist::GetClient() const noexcept
{
	return w_client;
}

std::vector<std::tuple<Product, unsigned int>> Wishlist::GetProductList() const noexcept
{
	return w_productList;
}

std::vector<std::tuple<Product, unsigned int>> Wishlist::GetProductListByCategory(ProductCategory category) const noexcept
{
	std::vector<std::tuple<Product, unsigned int>> categoryList;
	for (int i = 0; i < w_productList.size(); i++)
		if (std::get<0>(w_productList[i]).GetCategory() == category)
			categoryList.push_back(w_productList[i]);
	return categoryList;
}

std::vector<std::tuple<Product, unsigned int>> Wishlist::GetProductListPriceLower(float price) const noexcept
{
	std::vector<std::tuple<Product, unsigned int>> filteredList;
	for (int i = 0; i < w_productList.size(); i++)
		if (std::get<0>(w_productList[i]).GetPrice() <= price)
			filteredList.push_back(w_productList[i]);
	return filteredList;
}

std::vector<std::tuple<Product, unsigned int>> Wishlist::GetProductListPriceHigher(float price) const noexcept
{
	std::vector<std::tuple<Product, unsigned int>> filteredList;
	for (int i = 0; i < w_productList.size(); i++)
		if (std::get<0>(w_productList[i]).GetPrice() >= price)
			filteredList.push_back(w_productList[i]);
	return filteredList;
}

std::vector<std::tuple<Product, unsigned int>> Wishlist::GetProductListRatingHigher(float rating) const noexcept
{
	std::vector<std::tuple<Product, unsigned int>> filteredList;
	for (int i = 0; i < w_productList.size(); i++)
		if (std::get<0>(w_productList[i]).GetRating() >= rating)
			filteredList.push_back(w_productList[i]);
	return filteredList;
}

float Wishlist::GetTotalPrice()
{
	RefreshWishlistPrice();
	return w_totalPrice;
}

float Wishlist::GetPriceForCategory(ProductCategory category) const noexcept
{
	float price = 0;
	std::vector<std::tuple<Product, unsigned int>> categoryList;
	for (int i = 0; i < w_productList.size(); i++)
		if (std::get<0>(w_productList[i]).GetCategory() == category)
			price = price + std::get<0>(w_productList[i]).GetPrice() * std::get<1>(w_productList[i]);
	return price;
}

void Wishlist::AddProduct(Product& product, unsigned int pieces)
{
	w_productList.push_back(std::make_tuple(product, pieces));
	RefreshWishlistPrice();
}

void Wishlist::RefreshWishlistPrice()
{
	w_totalPrice = 0;
	for (int i = 0; i < w_productList.size(); i++)
	{
		w_totalPrice = w_totalPrice + std::get<0>(w_productList[i]).GetPrice() * std::get<1>(w_productList[i]);
	}
}

void Wishlist::RemoveProduct(Product prod)
{
	for (int i = 0; i < w_productList.size(); i++)
		if (std::get<0>(w_productList[i]).GetName() == prod.GetName())
		{
			w_productList.erase(w_productList.begin() + i);
			break;
		}
}

void Wishlist::RemoveProductsFromCategory(ProductCategory category)
{
	for (int i = 0; i < w_productList.size(); i++)
		if (std::get<0>(w_productList[i]).GetCategory() == category)
		{
			w_productList.erase(w_productList.begin() + i);
			i--;
		}
}

void Wishlist::SendToCart(Product prod)
{
	//w_client.GetCart().AddToCart(prod);
	RemoveProduct(prod);
}

void Wishlist::EmptyWishlish()
{
	w_productList.clear();
	w_totalPrice = 0;
}

std::ostream& operator<<(std::ostream& out, const Wishlist& wishlist)
{
	out << "Continutul Wishlistului dumneavoastra este:" << std::endl;
	for (int i = 0; i < wishlist.GetProductList().size(); i++)
	{
		out << std::get<0>(wishlist.GetProductList()[i]).GetName();
	}

	out << "Pretul total: " << wishlist.w_totalPrice << '\n';
	return out;
}