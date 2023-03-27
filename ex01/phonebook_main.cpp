#include "phonebook_main.hpp"

bool is_number(std::string str)
{
	if(str.empty())
		return false;
	for(int i = 0; str[i]; i++)
	{
		if(!isdigit(str[i]))
			return false;
	}
	return true;
}

int main(void)
{
	PhoneBook repertoire;
	std::string str = "";
	std::string ask = "";

	while(true)
	{
		std::cout << "$> ";
		str = safe_getline();
		if(str == "ADD")
		{
			repertoire.new_user();
		}
		else if (str == "SEARCH")
		{
			repertoire.show_users();
			while(!is_number(ask) || std::atoi(ask.c_str()) > PhoneBook::get_id_gen() - 1)
			{
				std::cout << "$> Enter a user id : ";
				ask = safe_getline();
			}
			repertoire.get_user(std::atoi(ask.c_str())).show_user();
			ask = "";
		}
		else if (str == "EXIT")
			break ;
		str = "";
	}
	return (0);
}