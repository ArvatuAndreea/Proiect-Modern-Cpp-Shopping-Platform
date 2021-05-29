#include "Product.h"
#include "Distributor.h"

Product::Product(std::string name, ProductCategory productCategory, Distributor distributor, std::string description, std::vector<std::tuple<std::string, unsigned int>> reviewsList, float price, float rating, double stock, int discount) :
    p_name(name), p_productCategory(productCategory), p_distributor(distributor), p_productDescription(description), p_price(price), p_reviewsList(reviewsList), p_rating(rating), p_stock(stock), p_discount(discount)
{
}

Product::Product(Product const& other) :
    p_name(other.p_name), p_productCategory(other.p_productCategory), p_distributor(other.p_distributor), p_productDescription(other.p_productDescription), p_price(other.p_price), p_reviewsList(other.p_reviewsList), p_rating(other.p_rating), p_stock(other.p_stock), p_discount(other.p_discount)
{
}

Product::Product(Product&& that) noexcept
{
    swap(*this, that);
}

Product::Product()
{
}

std::string Product::GetName() const noexcept
{
    return p_name;
}

ProductCategory Product::GetCategory() const noexcept
{
    return p_productCategory;
}

Distributor Product::GetDistributor() const noexcept
{
    return p_distributor;
}

std::string Product::GetDescription() const noexcept
{
    return p_productDescription;
}

unsigned int Product::GetAverageReview()
{
    unsigned int average = 0;
    for (int i = 0; i < p_reviewsList.size(); i++)
        average += std::get<1>(p_reviewsList[i]);
    return average / p_reviewsList.size();
}

std::vector<std::tuple<std::string, unsigned int>> Product::GetReviewsList() noexcept
{
    return std::vector<std::tuple<std::string, unsigned int>>();
}

float Product::GetPrice() const noexcept
{
    return p_price;
}

float Product::GetRating() const noexcept
{
    return p_rating;
}

double Product::GetStock() const noexcept
{
    return p_stock;
}

int Product::GetDiscount() const noexcept
{
    return p_discount;
}

float Product::GetDiscountedPrice() const
{
    if (p_discount > 0)
    {
        return (p_discount / 100.0f) * p_price;
    }
    else
        return p_price;
}

bool Product::IsInStock() const
{
    return (p_stock > 0) ? true : false;
}

void Product::EditProductName(std::string& newName)
{
    /* TO DO when GUI is implemented: Check if user is a distributor, otherwhise don't give access to edit the product name. */

    if (newName.size() > 1)
    {
        if (newName != p_name)
        {
            p_name = newName;
        }
        else
        {
            std::cout << "The new name is the same as the old one.";
        }
    }
    else
    {
        std::cout << "Name must be at least 1 character long.";
    }
}

void Product::EditProductDescription(std::string& newDescription)
{
    /* TO DO when GUI is implemented: Check if user is a distributor, otherwhise don't give access to edit the product description. */

    if (newDescription.size() > 10)
    {
        if (newDescription != p_productDescription)
        {
            p_productDescription = newDescription;
        }
        else
        {
            std::cout << "The new description is the same as the old one.";
        }
    }
    else
    {
        std::cout << "Description must be at least 10 characters long.";
    }
}

void Product::EditProductCategory(ProductCategory& newCategory)
{
    /* TO DO when GUI is implemented: Check if user is a distributor, otherwhise don't give access to edit the product category. */

    if (newCategory != p_productCategory)
    {
        p_productCategory = newCategory;
    }
    else
    {
        std::cout << "Category is the same as the old one.";
    }
}

void Product::EditProductDistributor(Distributor& newDistributor)
{
    /* TO DO when GUI is implemented: Check if user is a distributor, otherwhise don't give access to edit the product distributor. */

    p_distributor = newDistributor;
}

void Product::EditProductPrice(float newPrice)
{
    /* TO DO when GUI is implemented: Check if user is a distributor, otherwhise don't give access to edit the product price. */

    if (newPrice > 0)
    {
        if (newPrice != p_price)
        {
            p_price = newPrice;
        }
        else
        {
            std::cout << "Price is the same as the old one.";
        }
    }
    else
    {
        std::cout << "Price must be greater than 0.";
    }
}

void Product::RetrievalStock(double newstock)
{
    if (p_stock == 0)
    {
        if (newstock > 0)
            p_stock = newstock;

    }
    else
        std::cout << "The number of products in stock are: " << p_stock;
}

Product& Product::operator=(Product const& other)
{
    Product copy(other);
    swap(*this, copy);
    return *this;
}

Product& Product::operator=(Product&& that) noexcept
{
    swap(*this, that);
    return *this;
}

std::istream& operator>>(std::istream& fin, Product& product)
{
    fin >> product.p_name;
    SelectProductCategory(product.p_productCategory);
    fin >> product.p_stock >> product.p_distributor >> product.p_productDescription >> product.p_price >> product.p_rating >> product.p_discount;
    return fin;
}

std::ostream& operator<<(std::ostream& out, const Product& product)
{
    out << product.p_name << '\n';
    out << "Categorie" << ProductCategoryToString(product.p_productCategory) << '\n';
    out << "Stoc: " << product.p_stock << '\n';
    out << "Distribuitor: " << product.p_distributor.getName() << '\n';
    out << "Description: " << product.p_productDescription << '\n';
    out << "Pret: " << product.p_price << '\n';
    out << "Rating: " << product.p_rating << '\n';
    out << "Discount: " << product.p_discount << '\n';
    return out;
}

void swap(Product& lhs, Product& rhs) noexcept
{
    std::swap(lhs.p_name, rhs.p_name);
    std::swap(lhs.p_stock, rhs.p_stock);
    std::swap(lhs.p_productCategory, rhs.p_productCategory);
    std::swap(lhs.p_distributor, rhs.p_distributor);
    std::swap(lhs.p_productDescription, rhs.p_productDescription);
    std::swap(lhs.p_reviewsList, rhs.p_reviewsList);
    std::swap(lhs.p_price, rhs.p_price);
    std::swap(lhs.p_rating, rhs.p_rating);
    std::swap(lhs.p_discount, rhs.p_discount);
}
