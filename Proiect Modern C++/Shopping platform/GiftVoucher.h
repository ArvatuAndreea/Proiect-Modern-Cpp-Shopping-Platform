#pragma once
#ifndef GIFTVOUCHER_H
#define GIFTVOUCHER_H
#include <iostream>
class GiftVoucher
{
private:
	std::string v_name;
	std::string v_emailAddress;
	std::string v_phoneNumber;
	float v_value;
	std::string v_optionalMessage;
public:
	GiftVoucher(std::string name, std::string email, std::string phone, float value);
	GiftVoucher() = default;
	GiftVoucher(GiftVoucher&&);
	GiftVoucher(GiftVoucher const& other);
	GiftVoucher& operator= (GiftVoucher&&) = default;
	std::string GetName()const noexcept;
	std::string GetEmail()const noexcept;
	std::string GetPhone()const noexcept;
	std::string GetOptionalmessage()const noexcept;
	float GetValue()const noexcept;
	friend std::istream& operator>> (std::istream& in, GiftVoucher& voucher);
	friend std::ostream& operator<< (std::ostream& out, GiftVoucher& voucher);

};
#endif // !GIFTVOUCHER_H

