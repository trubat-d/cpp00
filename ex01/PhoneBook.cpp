#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

PhoneBook::PhoneBook(PhoneBook &other)
{
	for(int i = 0; i < 8; i++)
	{
		this->users[i] = other.users[i];
	}
}

PhoneBook&	PhoneBook::operator=(const PhoneBook& other)
{
	for(int i = 0; i < 8; i++)
	{
		this->users[i] = other.users[i];
	}
	return *this;
}

void PhoneBook::new_user(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int id = 7;

	if(PhoneBook::_id_gen <= 7) {
		id = PhoneBook::_id_gen;
		PhoneBook::_id_gen+= 1;
	}
	else
		update_ids();
	while(first_name == "")
	{
		std::cout << "Enter first name :";
		first_name = safe_getline();
	}
	while(last_name == "")
	{
		std::cout << "Enter last name :";
		last_name = safe_getline();
	}
	while (nickname == "")
	{
		std::cout << "Enter nickname :";
		nickname = safe_getline();
	}
	while(phone_number == "")
	{
		std::cout << "Enter phone_number :";
		phone_number = safe_getline();
	}
	while(darkest_secret == "")
	{
		std::cout << "Enter darkest secret :";
		darkest_secret = safe_getline();
	}
	this->users[id].update_user(first_name, last_name, nickname, phone_number, darkest_secret, id);
}

void PhoneBook::update_ids(void)
{
	for(int i = 0; i < 7; i++)
	{
		this->users[i] = this->users[i+1];
	}
}

void	PhoneBook::show_users(void) const
{
	int i = 0;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while(i < 8)
	{
		if(this->users[i].get_id() == i)
		{
			this->format_str(std::to_string(this->users[i].get_id()));
			std::cout << "|";
			this->format_str(this->users[i].get_first_name());
			std::cout << "|";
			this->format_str(this->users[i].get_last_name());
			std::cout << "|";
			this->format_str(this->users[i].get_nickname());
			std::cout << std::endl;
		}
		i++;
	}
}

void PhoneBook::format_str(std::string str) const
{
	int size = str.length();
	int i = 0;
	int j = 0;

	if (size <= 10)
	{
		while(i++ < 10 - size)
			std::cout << " ";
		while(j <= 10 - i + 1)
		{
			std::cout << str[j++];
		}
	}
	else if(size > 10)
	{
		while(j < 9)
			std::cout << str[j++];
		std::cout << ".";
	}
}

int PhoneBook::get_oldest(void) const
{
	for(int i = 0; i < 8; i++)
		if(this->users[i].get_id() == -1)
			return (i);
	return (-1);
}

Contact &PhoneBook::get_user(int id)
{
	return (this->users[id]);
}

int PhoneBook::_id_gen = 0;

int PhoneBook::get_id_gen(void)
{
	return PhoneBook::_id_gen;
}