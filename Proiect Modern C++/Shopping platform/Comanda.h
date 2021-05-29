#pragma once
#ifndef COMANDA_H
#define COMANDA_H

#include "Client.h"
#include "Shopping_Cart.h"
#include "FirmaCurier.h"
#include <iostream>

class Shopping_Cart;
class FirmaCurier;


class Comanda
{
private:
	Client c_client;
	Shopping_Cart c_cart;
	FirmaCurier c_curier;

public:
	Comanda(Client client, Shopping_Cart cart, FirmaCurier curier);
	Comanda() = default;
	Comanda(Comanda&&);
	Comanda& operator= (Comanda&&) = default;
	Client GetClient() const noexcept;
	Shopping_Cart GetCart() const noexcept;
	FirmaCurier GetCurier() const noexcept;
	friend std::istream& operator>> (std::istream& in, Comanda& comanda);
	friend std::ostream& operator<< (std::ostream& out, Comanda& comanda);

};

#endif // !COMANDA_H