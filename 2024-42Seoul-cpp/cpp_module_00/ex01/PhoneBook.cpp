#include <iostream>
#include "PhoneBook.hpp"
#include <string>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contact_count(0)
{
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::GetContactCount() const
{
	return this->contact_count;
}

std::string PhoneBook::TruncateText(const std::string& text, std::string::size_type length) const
{
	if (text.length() > length)
	{
		return text.substr(0, length - 1) + ".";
	}
	else
	{
		return text;
	}
}

void PhoneBook::AddContact(const Contact& contact)
{
	if (this->contact_count < 8)
	{
		this->contacts[this->contact_count] = contact;
		this->contact_count++;
	}
	else
	{
		for (int i = 0; i < this->contact_count - 1; i++)
		{
			this->contacts[i] = this->contacts[i + 1];
		}
		this->contacts[this->contact_count - 1] = contact;
	}
}

void PhoneBook::DisplayContacts() const
{
	if (this->contact_count == 0)
	{
		std::cout << "No contacts." << std::endl;
	}
	else
	{
		std::cout << "     index|first name| last name|  nickname" << std::endl;

		for (int i = 0; i < this->contact_count; i++)
		{
			std::ostringstream oss;
			oss << (i + 1);
			std::string indexStr = oss.str();

			std::cout << std::setw(10) << indexStr << "|";
			std::cout << std::setw(10) << TruncateText(this->contacts[i].GetFirstName(), 10) << "|";
			std::cout << std::setw(10) << TruncateText(this->contacts[i].GetLastName(), 10) << "|";
			std::cout << std::setw(10) << TruncateText(this->contacts[i].GetNickname(), 10) << std::endl;
		}
	}
}

void PhoneBook::DisplayOneContact(int idx) const
{
	if (idx < 1 || idx > this->contact_count)
	{
		std::cout << "Invalid index." << std::endl;
	}
	else
	{
		Contact contact = this->contacts[idx - 1];
		std::cout << "[Contact Details]" << std::endl;
		std::cout << "First name: " << contact.GetFirstName() << std::endl;
		std::cout << "Last name: " << contact.GetLastName() << std::endl;
		std::cout << "Nickname: " << contact.GetNickname() << std::endl;
		std::cout << "Phone number: " << contact.GetPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contact.GetDarkestSecret() << std::endl;
	}
}