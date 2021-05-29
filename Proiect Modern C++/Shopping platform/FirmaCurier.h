#pragma once
#ifndef FIRMACURIER_H
#define FIRMACURIER_H


#include<iostream>
class FirmaCurier
{
private:
	std::string f_nume;
	std::string f_adresa_sediu;
	std::string f_numar_telefon;
public:
	std::string GetNume() const noexcept;
	std::string GetAdresaSediu() const noexcept;
	std::string GetNumarTelefon() const noexcept;

	FirmaCurier(std::string, std::string, std::string);
	FirmaCurier()=default;
	FirmaCurier(FirmaCurier const& other);
	FirmaCurier(FirmaCurier&&);
	FirmaCurier& operator= (FirmaCurier&&) = default;

	friend std::istream& operator>> (std::istream& in, FirmaCurier& curier);
	friend std::ostream& operator<<(std::ostream& out, FirmaCurier& curier);

};

#endif // !FIRMACURIER_H