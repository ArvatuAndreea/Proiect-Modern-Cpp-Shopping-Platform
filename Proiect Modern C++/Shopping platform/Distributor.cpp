#include "Distributor.h"
#include "Product.h"

Distributor::Distributor(std::string name, std::string phone, std::string address, std::string email, std::string uniqueRegistrationCode, std::string IBAN, std::string bank, std::vector<Product> ourProducts) :
    d_name(name), d_phone(phone), d_address(address), d_email(email), d_uniqueRegistrationCode(uniqueRegistrationCode), d_IBAN(IBAN), d_bank(bank), d_ourProducts(ourProducts)
{
}

Distributor::Distributor(Distributor&& obj) noexcept
{
    *this = std::move(obj);
}

Distributor Distributor::operator=(Distributor const& other)
{
    Distributor distributor;
    distributor.d_name = other.d_name;
    distributor.d_phone = other.d_phone;
    distributor.d_address = other.d_address;
    distributor.d_email = other.d_email;
    distributor.d_uniqueRegistrationCode = other.d_uniqueRegistrationCode;
    distributor.d_IBAN = other.d_IBAN;
    distributor.d_bank = other.d_bank;
    distributor.d_ourProducts = other.d_ourProducts;
    return distributor;
}

Distributor::Distributor(Distributor const& other) :
    d_name(other.d_name), d_phone(other.d_phone), d_address(other.d_address), d_email(other.d_email), d_uniqueRegistrationCode(other.d_uniqueRegistrationCode), d_IBAN(other.d_IBAN), d_bank(other.d_bank), d_ourProducts(other.d_ourProducts)
{
}

std::string Distributor::getName() const noexcept
{
    return d_name;
}

std::string Distributor::getPhone() const noexcept
{
    return d_phone;
}

std::string Distributor::getAddress() const noexcept
{
    return d_address;
}
std::string Distributor::getEmail()const noexcept
{
    return d_email;
}
std::string Distributor::getUniqueRegistrationCode()const noexcept
{
    return d_uniqueRegistrationCode;
}
std::string Distributor::getIBAN()const noexcept
{
    return d_IBAN;
}
std::string Distributor::getBank()const noexcept
{
    return d_bank;
}
std::vector<Product>Distributor::getProducts() const noexcept
{
    return d_ourProducts;
}


std::istream& operator>>(std::istream& in, Distributor& distributor)
{
    in >> distributor.d_name >> distributor.d_phone >> distributor.d_address >> distributor.d_email >> distributor.d_uniqueRegistrationCode >> distributor.d_IBAN >> distributor.d_bank;
    Product aux;
    while (in >> aux)
    {
        distributor.d_ourProducts.push_back(aux);
        in >> aux;
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Distributor& distributor)
{
    out << "Datele distribuitorului: \n";
    out << "Nume: " << distributor.d_name << '\n';
    out << "Telefon: " << distributor.d_phone << '\n';
    out << "Adresa: " << distributor.d_address << '\n';
    out << "Email: " << distributor.d_email << '\n';
    out << "Cod de inregistrare: " << distributor.d_uniqueRegistrationCode << '\n';
    out << "IBAN: " << distributor.d_IBAN << '\n';
    out << "Banca: " << distributor.d_bank << '\n';
    out << "Lista de produse: \n";
    for (int i = 0; i < distributor.d_ourProducts.size(); i++)
        out << distributor.d_ourProducts[i] << '\n';
    return out;
}
