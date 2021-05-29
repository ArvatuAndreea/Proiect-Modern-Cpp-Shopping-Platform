#include "Shopping_Cart.h"
#include <iostream>

#include "Client.h"
#include "GiftVoucher.h"
#include "Product.h"

Client Shopping_Cart::GetClient()const noexcept
{
    return s_client;
}
GiftVoucher Shopping_Cart::GetVoucher() const noexcept
{
    return s_voucher;
}

float Shopping_Cart::GetTaxaTransport() const noexcept
{
    return s_TAXAtransport;
}
int Shopping_Cart::GetPieces()const noexcept
{
    return s_pieces;
}
Product Shopping_Cart::GetProduct() const noexcept
{
    return s_product;
}

float Shopping_Cart::GetTotal()
{
    CalculateTotal();
    return s_TOTAL;
}
void Shopping_Cart::RemoveProduct(Product prod)
{
    int pieces = 0;
    for (auto indice : s_productList)
    {
        for (auto index : indice)
            if (index.second.GetName() == prod.GetName())
            {
                pieces = index.first;
                indice.erase(indice.begin(), indice.find(index.first));
                CalculateTotal();
                break;
            }
        double newStock = prod.GetStock() + pieces;
        prod.RetrievalStock(newStock);
        break;
    }
}

std::vector<std::map<unsigned int, Product>> Shopping_Cart::GetProductList() const noexcept
{
    return s_productList;
}


Shopping_Cart::Shopping_Cart(Client& client, std::vector<std::map<unsigned int, Product>>& productlist, float totalPrice, float taxaTransport, Product product, GiftVoucher voucher, int pieces) :
    s_client(client), s_productList(productlist), s_TOTAL(totalPrice), s_TAXAtransport(taxaTransport), s_product(product), s_voucher(voucher), s_pieces(pieces)
{
}

Shopping_Cart::Shopping_Cart(Shopping_Cart const& other) :
    s_client(other.s_client), s_productList(other.s_productList), s_product(other.s_product), s_voucher(other.s_voucher), s_TAXAtransport(other.s_TAXAtransport), s_TOTAL(other.s_TOTAL), s_priceFreeTransport(other.s_priceFreeTransport), s_pieces(other.s_pieces)
{
}

Shopping_Cart::Shopping_Cart(Shopping_Cart&& obj)
{
    *this = std::move(obj);
};

void Shopping_Cart::RemoveProduct(Product& prod, int pieces)
{
    for (auto indice : s_productList)
    {
        for (auto index : indice)
            if (index.second.GetName() == prod.GetName())
            {
                indice.erase(indice.begin(), indice.find(index.first));
                CalculateTotal();
                break;
            }
        double newStock = prod.GetStock() + pieces;
        prod.RetrievalStock(newStock);
        break;
    }
}

void Shopping_Cart::FreeTransport()
{
    if (s_TOTAL > s_priceFreeTransport)
        s_TAXAtransport = 0;
}
void Shopping_Cart::AddToCart(Product prod)
{
    AddToCart(prod, 1);
}
void Shopping_Cart::AddToCart(Product prod, int pieces)
{
    size_t index = s_productList.size();
    if (prod.GetStock() >= pieces)
    {
        s_productList[index++].insert(std::pair<int, Product>(pieces, prod));
        s_TOTAL += (pieces * prod.GetPrice());
        FreeTransport();
    }
    else
        std::cout << "The number of products in stock is lower than the pieces you want to buy!";

    double newstock = prod.GetStock() - pieces;
    prod.RetrievalStock(newstock);
}

void Shopping_Cart::CalculateTotal()
{
    s_TOTAL = 0;
    for (auto index : s_productList)
    {
        for (auto indice : index)
        {
            s_TOTAL += indice.second.GetPrice();
        }
    }
    s_TOTAL -= s_voucher.GetValue();
}

//Shopping_Cart::Shopping_Cart() : Shopping_Cart(" ", " ", " ", " ")
//{
//}



std::istream& operator>>(std::istream& fin, Shopping_Cart& cart)
{
    fin >> cart.s_product >> cart.s_pieces >> cart.s_voucher >> cart.s_TAXAtransport;
    return fin;
}

std::ostream& operator<<(std::ostream& out, const Shopping_Cart& cart)
{
    out << "Continutul cosului dvs. de cumparaturi este:" << std::endl;
    for (auto i : cart.s_productList)
    {
        for (auto j : i)
        {
            out << j.second.GetName() << std::endl;
        }
    }
    out << "Voucher value: " << cart.s_voucher.GetValue() << '\n';
    out << "Taxa transport: " << cart.s_TAXAtransport << '\n';
    out << "Pretul total: " << cart.s_TOTAL << '\n';
    return out;
}


