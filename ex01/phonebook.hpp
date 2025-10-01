/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:51:18 by mradouan          #+#    #+#             */
/*   Updated: 2025/09/29 14:03:51 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctype.h>

class PhoneBook
{
	private :
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string darkSecret;
		std::string	phoneNum;
		int			index;
	public :
		void setFirstName(std::string fName);
		void setLastName(std::string lName);
		void setNickName(std::string nName);
		void setDarkSecret(std::string dSecret);
		void setPhoneNumber(std::string pNum);
		void setIndex(int ind);

	
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string gettDarkSecret();
		std::string getPhoneNumber();
		int			getIndex();

};


















#endif