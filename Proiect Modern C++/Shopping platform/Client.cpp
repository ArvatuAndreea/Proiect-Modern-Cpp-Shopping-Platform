#include "Client.h"
#include <iostream>
#include "Wishlist.h"
#include "Comanda.h"
#include "GiftVoucher.h"
#include "Product.h"

std::string Client::GetName() const noexcept
{
    return c_name;
}

std::string Client::GetPhone() const noexcept
{
    return c_phone;
}

std::string Client::GetAddress() const noexcept
{
    return c_address;
}

std::string Client::GetEmail() const noexcept
{
    return c_email;
}

std::string Client::GetPassword() const noexcept
{
    return c_password;
}
std::string Client::GetCreditCard() const noexcept
{
    return c_creditCard;
}
Wishlist Client::GetWishlist() const noexcept
{
    return c_wishlist;
}
std::vector<Product> Client::GetRatings() const noexcept
{
    return c_myRatings;
}
std::vector<GiftVoucher>Client::GetVouchers() const noexcept
{
    return c_myVouchers;
}
std::vector<Product>Client::GetReturnedProducts() const noexcept
{
    return c_myReturnedProducts;
}
Client::Client(std::string name, std::string phone, std::string address, std::string email, std::string password, std::string creditCard, std::vector<Comanda> order_history, Wishlist wishlist, std::vector<Product> myRatings, std::vector<GiftVoucher> myVouchers, std::vector<Product> myReturnedProducts) :
    c_name(name), c_phone(phone), c_address(address), c_email(email), c_password(password), c_creditCard(creditCard), c_order_history(order_history), c_wishlist(wishlist), c_myRatings(myRatings), c_myVouchers(myVouchers), c_myReturnedProducts(myReturnedProducts)
{
}

Client::Client()
{
}

Client::Client(Client const& other) :
    c_name(other.c_name), c_phone(other.c_phone), c_address(other.c_address), c_email(other.c_email), c_password(other.c_password), c_creditCard(other.c_creditCard), c_order_history(other.c_order_history), c_wishlist(other.c_wishlist), c_myRatings(other.c_myRatings), c_myVouchers(other.c_myVouchers), c_myReturnedProducts(other.c_myReturnedProducts)
{
}

Client::Client(Client&& that) noexcept
{
    swap(*this, that);
}

std::istream& operator>>(std::istream& in, Client& client)
{
    in >> client.c_name >> client.c_phone >> client.c_address >> client.c_email >> client.c_password >> client.c_creditCard;
    return in;
}

std::ostream& operator<<(std::ostream& out, Client& client)
{
    out << "Datele clientului: \n";
    out << "Nume: " << client.c_name << '\n';
    out << "Telefon: " << client.c_phone << '\n';
    out << "Email: " << client.c_email << '\n';
    out << "Adresa: " << client.c_address << '\n';
    out << "Parola: ";
    for (int i = 0; i < client.c_password.size(); i++)
        out << '*';
    out << '\n';
    out << "Credit card: " << client.c_creditCard << '\n';
    out << "Wishlist: " << client.c_wishlist << '\n';
    out << "Istoricul comenzilor: \n";
    for (int i = 0; i < client.c_order_history.size(); i++)
        out << i << '\n';
    out << "Evaluari: \n";
    for (int i = 0; i < client.c_myRatings.size(); i++)
        out << client.c_myRatings[i] << '\n';
    out << "Vouchers: \n";
    for (int i = 0; i < client.c_myVouchers.size(); i++)
        out << client.c_myVouchers[i] << '\n';
    out << "Produsele returnate: \n";
    for (int i = 0; i < client.c_myReturnedProducts.size(); i++)
        out << client.c_myReturnedProducts[i] << '\n';

    return out;
}

void swap(Client& lhs, Client& rhs) noexcept
{
    std::swap(lhs.c_name, rhs.c_name);
    std::swap(lhs.c_phone, rhs.c_phone);
    std::swap(lhs.c_address, rhs.c_address);
    std::swap(lhs.c_email, rhs.c_email);
    std::swap(lhs.c_password, rhs.c_password);
    std::swap(lhs.c_creditCard, rhs.c_creditCard);
    std::swap(lhs.c_order_history, rhs.c_order_history);
    std::swap(lhs.c_wishlist, rhs.c_wishlist);
    std::swap(lhs.c_myRatings, rhs.c_myRatings);
    std::swap(lhs.c_myVouchers, rhs.c_myVouchers);
    std::swap(lhs.c_myReturnedProducts, rhs.c_myReturnedProducts);
    std::swap(lhs.numarMinimCaractereParola, rhs.numarMinimCaractereParola);

}

std::vector<Comanda> Client::GetOrderHistory() const noexcept
{
    return c_order_history;
}


void Client::UpdateOrderHistory(Comanda new_command)
{
    c_order_history.push_back(new_command);
}

Client& Client::operator=(Client const& other)
{
    Client copy(other);
    swap(*this, copy);
    return *this;
}

Client& Client::operator=(Client&& that) noexcept
{
    swap(*this, that);
    return *this;
}

void Client::ChangeName(std::string& newName)
{
    if (newName != c_name)
        c_name = newName;
    else
        std::cout << "The new name is the same as the old one. \n";
}

void Client::ChangePassword(std::string& newPassword)
{
    if (newPassword.size() > numarMinimCaractereParola)
    {
        if (newPassword != c_password)
            c_password = newPassword;
        else
            std::cout << "The new password is the same as the old one.";
    }
    else
        std::cout << " Password must be at least 8 characters long.";
}
void Client::ChangeAddress(std::string& newAddress)
{
    if (newAddress.size() > 6)
    {
        if (newAddress != c_address)
            c_address = newAddress;
        else
            std::cout << "The new address is the same as the old one.";
    }
    else
        std::cout << " Address must be at least 6 characters long.";

}
void Client::ChangePhone(std::string& newPhone)
{
    if (newPhone.size() == 10)
    {
        if (newPhone != c_phone)
            c_phone = newPhone;
        else
            std::cout << "The new phone is the same as the old one.";
    }
    else
        std::cout << " Phone must have 10 characters long.";
}

void Client::ChangeEmail(std::string& newEmail)
{
    if (newEmail.size() >= 11)
    {
        if (newEmail != c_email)
            c_email = newEmail;
        else
            std::cout << "The new email is the same as the old one. \n";
    }
    else
        std::cout << " Email must be at least 11 characters long. \n";
}

void Client::ChangeCreditCard(std::string& newCreditCard)
{
    if (newCreditCard.size() >= 12)
    {
        if (newCreditCard != c_creditCard)
            c_creditCard = newCreditCard;
        else
            std::cout << "The new credit card is the same as the old one. \n";
    }
    else
        std::cout << " Credit card must be at least 12 characters long. \n";
}

void Client::AddVoucher(std::vector<GiftVoucher>c_myVouchers, GiftVoucher newVoucher)
{
    c_myVouchers.push_back(newVoucher);
}
void Client::LoginAccount(Client& client)
{

}
void Client::CreatenewAccount(Client& newclient)
{
    if (newclient.c_email != c_email)
    {

    }
    else
        std::cout << "This email is already used for another account. \n";
    if (newclient.c_password.length() >= numarMinimCaractereParola)
    {

    }
    else
        std::cout << "The pasword is too short.Password must be at least 8 characters long. \n";
}
void Client::ForgotMyPassword(std::string& newPassword)
{
    std::cout << "If you forgot your password please enter your email and than enter the new passowrd and click on 'submit'.In the end check your email for the last step. \n";
    std::cin >> c_email;
    std::cin >> newPassword;
    if (newPassword.length() < numarMinimCaractereParola)
    {
        std::cout << "The password must be at least 8 characters long.Please enter a longer password. \n ";
        std::cin >> newPassword;
    }
}