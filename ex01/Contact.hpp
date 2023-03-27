#ifndef CPP_CONTACT_HPP
#define CPP_CONTACT_HPP

#include <iostream>
#include <string>
class Contact {
public:
	void		show_user() const;
	int			get_id() const;
	void		lower_id();
	std::string	get_first_name() const;
	std::string	get_last_name() const;
	std::string	get_nickname() const;
	std::string	get_phone_number() const;
	std::string	get_darkest_secret() const;
	void		update_user(std::string f_name ,std::string l_name, std::string n_name, std::string p_num, std::string d_sec, int id);
	Contact&	operator=(const Contact& other);
	Contact();
	Contact(Contact& other);
    Contact(std::string f_name ,std::string l_name, std::string n_name, std::string p_num, std::string d_sec, int id);
    ~Contact();
private:
    std::string	_first_name;
    std::string	_last_name;
    std::string	_nickname;
    std::string	_phone_number;
    std::string	_darkest_secret;
    int			_id;
};

std::string	safe_getline(void);

#endif //CPP_CONTACT_HPP
