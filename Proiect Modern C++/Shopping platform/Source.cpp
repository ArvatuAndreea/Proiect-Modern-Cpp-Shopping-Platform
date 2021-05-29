#include <iostream>
#include <fstream>
#include <cstring>
#include "Shopping_Cart.h"
#include "Client.h"
#include "Comanda.h"
#include "Distributor.h"
#include "FirmaCurier.h"
#include "Product.h"
#include "Wishlist.h"
#include "GiftVoucher.h"
#include "ProductCategory.h"

#include "../Logging/Logging.h"

int main()
{
	std::ofstream of("syslog.log", std::ios::app);
	Logger logger(of);
	logger.log("Started application", Logger::Level::Info);

	int index;
	Client client;
	Shopping_Cart cart;
	Wishlist wishlist;
	Product prod;
	FirmaCurier curier;
	std::cout << "Introduceti Username si parola";
	std::cin >> client;
	std::cout << prod;
	std::cout << "Datele firmei de curierat sunt :" << std::endl;
	std::cout << curier;
	std::cout << std::endl;
	std::cout << "Pentru a adauga produse in cosul dvs de cumparaturi apasati tasta 1" << std::endl;
	std::cout << "Pentru a vedea continutul cosului dvs de cumparaturi apasati tasta 2" << std::endl;
	std::cout << "Pentru a elimina un produs din cosul de cumparaturi apasati tasta 3" << std::endl;
	std::cout << "Pentru a adauga produse in wishlist apasati tasta 4" << std::endl;
	std::cout << "Pentru a adauga un produs din wishlist in cosul de cumparaturi apasati tasta 5" << std::endl;
	std::cout << "Pentru a elimina un produs din wishlist apasati tasta 6" << std::endl;
	std::cout << "Pentru a vizualiza istoricul de comenzi apasati tasta 7" << std::endl;
	std::cout << "Pentru a finaliza comanda apasati tasta 0" << std::endl;
	std::cout << "Pentru a vedea datele contului dvs apasati tasta 8" << std::endl;
	std::cout << "Pentru a modifica datele contului dvs apasati tasta 9" << std::endl;
	std::cin >> index;
	do
	{
		switch (index)
		{
		case 1:
		{
			cart.AddToCart(prod);
			break;
		}
		case 2:
		{
			std::cout << cart;
			break;
		}
		case 3:
		{
			cart.RemoveProduct(prod);
			break;
		}
		case 4:
		{
			int pieces;
			std::cin >> pieces;
			wishlist.AddProduct(prod, pieces);
			break;
		}
		case 5:
		{
			wishlist.SendToCart(prod);
			break;
		}
		case 6:
		{
			wishlist.RemoveProduct(prod);
			break;
		}
		case 7:
		{
			client.GetOrderHistory();
			break;
		}
		case 8:
		{
			std::cout << client;
			break;
		}
		case 9:
		{
			std::cout << "Ce doriti sa modificati? \n";
			int choice;
			std::cout << "Pentru a schimba numele apasati 0 \n";
			std::cout << "Pentru a schimba numarul de telefon apasati 1 \n";
			std::cout << "Pentru a schimba adresa apasati 2 \n";
			std::cout << "Pentru a schimba adresa de email apasati 3 \n";
			std::cout << "Pentru a schimba parola apasati 4 \n";
			std::cout << "Pentru a schimba cardul de credit apasati 5 \n";
			std::cout << "Pentru a iesi din sectiunea modificare date apasati 6 \n";
			std::cin >> choice;
			do {
				switch (choice)
				{
				case 0:
				{	std::string newName;
					std::cout << "Introduceti noul nume: ";
					std::cin >> newName;
					client.ChangeName(newName);
					break;
				}
				case 1:
				{
					std::string newPhone;
					std::cout << "Introduceti noul numar de telefon: ";
					std::cin >> newPhone;
					client.ChangePhone(newPhone);
					break;
				}
				case 2:
				{
					std::string newAddress;
					std::cout << "Introduceti noua adresa: ";
					std::cin >> newAddress;
					client.ChangeAddress(newAddress);
					break;
				}
				case 3:
				{
					std::string newEmail;
					std::cout << "Introduceti noua adresa de email: ";
					std::cin >> newEmail;
					client.ChangeEmail(newEmail);
					break;
				}
				case 4:
				{
					std::string newPassword;
					std::cout << "Introduceti noua parola: ";
					std::cin >> newPassword;
					client.ChangePassword(newPassword);
					break;
				}
				case 5:
				{
					std::string newCreditCard;
					std::cout << "Introduceti noul card de credit: ";
					std::cin >> newCreditCard;
					client.ChangeCreditCard(newCreditCard);
					break;
				}
				default:
				{
					std::cout << "Introducere invalida. \n";
					std::cout << "Introduceti din nou. \n";
					break;
				}
				}
			} while (choice != 6);
		}
		}
		std::cout << "Pentru a adauga produse in cosul dvs de cumparaturi apasati tasta 1" << std::endl;
		std::cout << "Pentru a vedea continutul cosului dvs de cumparaturi apasati tasta 2" << std::endl;
		std::cout << "Pentru a elimina un produs din cosul de cumparaturi apasati tasta 3" << std::endl;
		std::cout << "Pentru a adauga produse in wishlist apasati tasta 4" << std::endl;
		std::cout << "Pentru a adauga un produs din wishlist in cosul de cumparaturi apasati tasta 5" << std::endl;
		std::cout << "Pentru a elimina un produs din wishlist apasati tasta 6" << std::endl;
		std::cout << "Pentru a vizualiza istoricul de comenzi apasati tasta 7" << std::endl;
		std::cout << "Pentru a finaliza comanda apasati tasta 0" << std::endl;
		std::cout << "Pentru a vedea datele contului dvs apasati tasta 8" << std::endl;
		std::cout << "Pentru a modifica datele contului dvs apasati tasta 9" << std::endl;
		std::cin >> index;

	} while (index != 0);
	
	
	

	//client.UpdateOrderHistory();

	return 0;
}