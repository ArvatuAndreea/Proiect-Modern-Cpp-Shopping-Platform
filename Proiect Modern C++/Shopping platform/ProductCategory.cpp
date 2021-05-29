#include "ProductCategory.h"


std::string ProductCategoryToString(ProductCategory category)
{
	switch (category)
	{
	case ProductCategory::CLOTHING: return "CLOTHING"; 
	case ProductCategory::FOOD: return "FOOD"; 
	case ProductCategory::TECHNOLOGY: return "TECHNOLOGY"; 
	case ProductCategory::FURNITURE: return "FURNITURE"; 
	case ProductCategory::SPORTS: return "SPORTS"; 
	case ProductCategory::BOOKS: return "BOOKS"; 
	}
}

void SelectProductCategory(ProductCategory& category)
{
	std::cout << "Alegeti categori produsului";
	int temp;
		std::cin >> temp;
		switch (temp)
		{
		case 1: category = ProductCategory::CLOTHING;break;
		case 2: category = ProductCategory::FOOD;break;
		case 3: category = ProductCategory::TECHNOLOGY;break;
		case 4: category = ProductCategory::FURNITURE;break;
		case 5: category = ProductCategory::SPORTS;break;
		case 6: category = ProductCategory::BOOKS;break;
		default: std::cout << "Valoarea introdusa este invalida";std::cin >> temp;
		}

	
}

ProductCategory NumberToCategory(uint16_t number)
{
	switch (number)
	{
	case 1:
		return ProductCategory::CLOTHING;
	case 2:
		return ProductCategory::FOOD;
	case 3:
		return ProductCategory::TECHNOLOGY;
	case 4:
		return ProductCategory::FURNITURE;
	case 5:
		return ProductCategory::SPORTS;
	case 6:
		return ProductCategory::BOOKS;
	}
}

uint16_t CategoryToNumber(ProductCategory category)
{
	switch (category)
	{
	case ProductCategory::CLOTHING:
		return 1;
	case ProductCategory::FOOD:
		return 2;
	case ProductCategory::TECHNOLOGY:
		return 3;
	case ProductCategory::FURNITURE:
		return 4;
	case ProductCategory::SPORTS:
		return 5;
	case ProductCategory::BOOKS:
		return 6;
	}
}
