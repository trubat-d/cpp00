#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
public:
    void		new_user(void);
    void		search_user(void);
	Contact		&get_user(int id);
	int			get_oldest(void) const;
	void		show_users(void) const;
	void		format_str(std::string str) const;
	void		update_ids(void);
	static int	get_id_gen(void);
	PhoneBook&	operator=(const PhoneBook& other);
    PhoneBook();
	PhoneBook(PhoneBook &other);
    ~PhoneBook();
private:
    Contact			users[8];
	static int		_id_gen;
};

#endif
