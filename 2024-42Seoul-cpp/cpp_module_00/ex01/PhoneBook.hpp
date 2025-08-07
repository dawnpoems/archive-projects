#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		contact_count;
	std::string TruncateText(const std::string& text, std::string::size_type length) const;

public:
	PhoneBook();
	~PhoneBook();

	void	AddContact(const Contact& contact);
	int		GetContactCount() const;
	void	DisplayContacts() const;
	void	DisplayOneContact(int idx) const;
};

#endif