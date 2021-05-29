#include "FirmaCurier.h"
#include <iostream>
std::string FirmaCurier::GetNume() const noexcept
{
    return f_nume;
}

std::string FirmaCurier::GetAdresaSediu() const noexcept
{
    return f_adresa_sediu;
}

std::string FirmaCurier::GetNumarTelefon() const noexcept
{
    return f_numar_telefon;
}

FirmaCurier::FirmaCurier(std::string nume, std::string adresa, std::string nr_telefon) :
    f_nume(nume), f_adresa_sediu(adresa), f_numar_telefon(nr_telefon)
{
}

FirmaCurier::FirmaCurier(FirmaCurier const& other) :
    f_nume(other.f_nume), f_adresa_sediu(other.f_adresa_sediu), f_numar_telefon(other.f_numar_telefon)
{
}

FirmaCurier::FirmaCurier(FirmaCurier&& obj)
{
    *this = std::move(obj);
}

std::istream& operator>>(std::istream& in, FirmaCurier& curier)
{
    in >> curier.f_nume >> curier.f_adresa_sediu >> curier.f_numar_telefon;
    return in;
}

std::ostream& operator<<(std::ostream& out, FirmaCurier& curier)
{
    out << curier.f_nume << curier.f_adresa_sediu << curier.f_numar_telefon;
    return out;
}
