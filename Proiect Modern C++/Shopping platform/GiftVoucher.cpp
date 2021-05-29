#include "GiftVoucher.h"

GiftVoucher::GiftVoucher(std::string name, std::string email, std::string phone, float value) :
	v_name(name), v_emailAddress(email), v_phoneNumber(phone), v_value(value)
{
}

GiftVoucher::GiftVoucher(GiftVoucher&& obj)
{
	*this = std::move(obj);
}

GiftVoucher::GiftVoucher(GiftVoucher const& other) :
	v_name(other.v_name), v_emailAddress(other.v_emailAddress), v_phoneNumber(other.v_phoneNumber), v_value(other.v_value), v_optionalMessage(other.v_optionalMessage)
{
}

std::string GiftVoucher::GetName() const noexcept
{
	return v_name;
}

std::string GiftVoucher::GetEmail() const noexcept
{
	return v_emailAddress;
}

std::string GiftVoucher::GetPhone() const noexcept
{
	return v_phoneNumber;
}

std::string GiftVoucher::GetOptionalmessage() const noexcept
{
	return v_optionalMessage;
}

float GiftVoucher::GetValue() const noexcept
{
	return v_value;
}

std::istream& operator>>(std::istream& in, GiftVoucher& voucher)
{
	std::cout << "Name: \n";
	in >> voucher.v_name;
	std::cout << "Email address: \n";
	in >> voucher.v_emailAddress;
	std::cout << "Phone number \n";
	in >> voucher.v_phoneNumber;
	std::cout << "Value: ";
	in >> voucher.v_value;
	std::cout << "If you want to add a message with the  gift voucher: \n";
	in >> voucher.v_optionalMessage;
	return in;
}

std::ostream& operator<<(std::ostream& out, GiftVoucher& voucher)
{
	std::cout << "Name: " << voucher.v_name << '\n';
	std::cout << "Email address: " << voucher.v_emailAddress << '\n';
	std::cout << "Phone number: " << voucher.v_phoneNumber << '\n';
	std::cout << "Value: " << voucher.v_value << '\n';
	std::cout << "Message: " << voucher.v_optionalMessage << '\n';
	return out;
}
