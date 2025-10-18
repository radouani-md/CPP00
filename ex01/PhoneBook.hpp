#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

# define SIZE 8

class PhoneBook
{
	private :
		Contact	contacts[SIZE];
		int	len_contact;
	
	public :
		void	displayData();
		void	addNewContact();
		void	initialize_len();
};



#endif