#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
					Contact(
						std::string _firstname = "",
						std::string _lastname = "",
						std::string _nickname = "",
						std::string _phonenumber = "",
						std::string _darkestsecret = "");
					~Contact(void);
					Contact(const Contact &contact);
		Contact		&operator=(const Contact &contact);

		void		print(void) const;

		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	darkestsecret;
};

#endif
