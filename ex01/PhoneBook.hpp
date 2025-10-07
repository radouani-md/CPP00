/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:51:18 by mradouan          #+#    #+#             */
/*   Updated: 2025/10/03 18:14:06 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include <string>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <ctype.h>

# define SIZE 3

class PhoneBook
{
	private :
		Contact	contacts[SIZE];
		int	len_contact;
	
	public :
		void	displayData();
		void	addNewContact();
};



#endif