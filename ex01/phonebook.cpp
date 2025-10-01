/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:02:33 by mradouan          #+#    #+#             */
/*   Updated: 2025/09/29 14:04:01 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	PhoneBook::setFirstName(std::string fName)
{
	firstName = fName;
}

void	PhoneBook::setLastName(std::string lName)
{
	lastName = lName;
}

void	PhoneBook::setNickName(std::string nName)
{
	nickName = nName;
}

void	PhoneBook::setDarkSecret(std::string dSecret)
{
	darkSecret = dSecret;
}

void	PhoneBook::setPhoneNumber(std::string pNum)
{
	phoneNum = pNum;
}
void	PhoneBook::setIndex(int ind)
{
	index = ind;
}

std::string PhoneBook::getFirstName() { return (firstName); }
std::string PhoneBook::getLastName() { return (lastName); }
std::string PhoneBook::getNickName() { return (nickName); }
std::string PhoneBook::gettDarkSecret() { return (darkSecret); }
std::string PhoneBook::getPhoneNumber() { return (phoneNum); }
int			PhoneBook::getIndex() { return (index); }