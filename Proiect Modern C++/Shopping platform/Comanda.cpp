#include "Comanda.h"
#include <iostream>

#include "FirmaCurier.h"
#include "Client.h"
#include "Shopping_Cart.h"

Client Comanda::GetClient() const noexcept
{
    return c_client;
}

Shopping_Cart Comanda::GetCart() const noexcept
{
    return c_cart;
}

FirmaCurier Comanda::GetCurier() const noexcept
{
    return c_curier;
}

Comanda::Comanda(Client client, Shopping_Cart cart, FirmaCurier curier) :
    c_client(client), c_cart(cart), c_curier(curier)
{
}

Comanda::Comanda(Comanda&& obj)
{
    *this = std::move(obj);
}

std::istream& operator>>(std::istream& in, Comanda& comanda)
{

    return in;
}
std::ostream& operator<<(std::ostream& out, Comanda& comanda)
{
    out << comanda.c_cart << comanda.c_client << comanda.c_curier;
    return out;
}
