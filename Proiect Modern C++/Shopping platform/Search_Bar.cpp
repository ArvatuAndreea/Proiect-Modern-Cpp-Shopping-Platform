#include "Search_Bar.h"
#include "Product.h"


Product Search_Bar::LowerPrice(Product prod1, Product prod2)
{
	if (prod1.GetPrice() < prod2.GetPrice())
		return prod1;
	else
		return prod2;
}

Product Search_Bar::HigherPrice(Product prod1, Product prod2)
{
	if (prod1.GetPrice() > prod2.GetPrice())
		return prod1;
	else
		return prod2;
}

Search_Bar::Search_Bar(std::vector<Product> listofProducts, ProductCategory listofCategories) :
	s_listOfProducts(listofProducts), s_listOfCategories(listofCategories)
{
}

Search_Bar::Search_Bar(Search_Bar&& obj)
{
	*this = std::move(obj);
}

std::vector<Product> Search_Bar::GetListOfProducts() const noexcept
{
	return s_listOfProducts;
}

ProductCategory Search_Bar::GetListOfCategories() const noexcept
{
	return s_listOfCategories;
}

void Search_Bar::SearchByNameOfProduct(std::string name_of_product)
{
	for (auto i : s_listOfProducts)
	{
		if (i.GetName() == name_of_product)
			std::cout << i.GetName() << " " << i.GetPrice() << std::endl;
	}
}

void Search_Bar::SearchByNameOfCategory(std::string name_of_category)
{

}

void Search_Bar::FilterProductsByLowerPrice()
{

	std::sort(s_listOfProducts.begin(), s_listOfProducts.end());
	for (auto i : s_listOfProducts)
	{
		std::cout << i.GetName() << " " << i.GetPrice() << std::endl;
	}
}

void Search_Bar::FilterProductByHigherPrice()
{
	std::sort(s_listOfProducts.begin(), s_listOfProducts.end());
	for (int i = s_listOfProducts.size() - 1; i >= 0; i--)
	{
		std::cout << s_listOfProducts[i].GetName() << " " << s_listOfProducts[i].GetPrice() << std::endl;
	}
}

void Search_Bar::FilterProductsByRating()
{
	for (int index1 = 0; index1 < s_listOfProducts.size() - 1; index1++)
		for (int index2 = index1 + 1; index2 < s_listOfProducts.size(); index2++)
		{
			if (s_listOfProducts[index1].GetRating() > s_listOfProducts[index2].GetRating())
				swap(s_listOfProducts[index1], s_listOfProducts[index2]);
		}

	for (auto i : s_listOfProducts)
		std::cout << i.GetName() << " " << i.GetPrice() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Search_Bar& bar)
{

	out << "Produsele: \n";
	for (auto i : bar.s_listOfProducts)
	{
		out << i.GetName() << " " << i.GetPrice() << " " << i.GetCategory() << " " << i.GetDiscount() << std::endl;
		out << i.GetDescription() << std::endl;
		std::cout << std::endl;
	}
	return out;
}