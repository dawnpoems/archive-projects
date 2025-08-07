#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(const std::string& first_name, const std::string& last_name, const std::string& nick_name, const std::string& phone_number, const std::string& darkest_secret)
	: first_name(first_name), last_name(last_name), nickname(nick_name), phone_number(phone_number), darkest_secret(darkest_secret)
{
}

Contact::~Contact()
{
}

void Contact::SetFirstName(const std::string& first_name)
{
	this->first_name = first_name;
}

void Contact::SetLastName(const std::string& last_name)
{
	this->last_name = last_name;
}

void Contact::SetNickname(const std::string& nick_name)
{
	this->nickname = nick_name;
}

void Contact::SetPhoneNumber(const std::string& phone_number)
{
	this->phone_number = phone_number;
}

void Contact::SetDarkestSecret(const std::string& darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

const std::string& Contact::GetFirstName() const
{
	return this->first_name;
}

const std::string& Contact::GetLastName() const
{
	return this->last_name;
}

const std::string& Contact::GetNickname() const
{
	return this->nickname;
}

const std::string& Contact::GetPhoneNumber() const
{
	return this->phone_number;
}

const std::string& Contact::GetDarkestSecret() const
{
	return this->darkest_secret;
}