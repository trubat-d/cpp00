#include "../../cpp00/ex01/Contact.hpp"

Contact::Contact()
{

	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	this->_id = -1;
}


Contact::Contact(std::string f_name ,std::string l_name, std::string n_name, std::string p_num, std::string d_sec, int id)
: _first_name(f_name) , _last_name(l_name),_nickname(n_name), _phone_number(p_num), _darkest_secret(d_sec), _id(id)
{

}

Contact::~Contact(void)
{

}

Contact::Contact(Contact& other)
{
	this->_first_name = other._first_name;
	this->_nickname = other._nickname;
	this->_last_name = other._last_name;
	this->_phone_number = other._phone_number;
	this->_darkest_secret = other._darkest_secret;
	this->_id = other._id;
}

Contact&	Contact::operator=(const Contact &other)
{
	this->_first_name = other.get_first_name();
	this->_last_name = other.get_last_name();
	this->_nickname = other.get_nickname();
	this->_phone_number = get_phone_number();
	this->_darkest_secret = get_darkest_secret();
	return *this;
}

void Contact::update_user(std::string f_name, std::string l_name, std::string n_name, std::string p_num,
						  std::string d_sec, int id)
{
		this->_id = id;
		this->_darkest_secret = d_sec;
		this->_phone_number = p_num;
		this->_nickname = n_name;
		this->_last_name = l_name;
		this->_first_name = f_name;
}

void Contact::show_user(void) const
{
	std::cout << this->_first_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phone_number << std::endl;
	std::cout << this->_darkest_secret << std::endl;
}

int Contact::get_id(void) const
{
	return (this->_id);
}

void Contact::lower_id(void)
{
	this->_id--;
}

std::string	Contact::get_first_name() const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name() const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname() const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number() const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret() const
{
	return (this->_darkest_secret);
}

std::string	safe_getline(void)
{
	std::string tmp = "";
	while(!std::getline(std::cin, tmp) || tmp.length() == 0)
	{
		if(std::cin.fail())
		{
			std::cout << "\nClosing the prompt !" << std::endl;
			exit(0);
		}
		if(tmp.length() == 0)
			return "";
		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}
	return tmp;
}