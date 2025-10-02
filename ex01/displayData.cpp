/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd_md_haker <rd_md_haker@student.42.fr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 09:08:02 by rd_md_haker       #+#    #+#             */
/*   Updated: 2025-10-02 09:08:02 by rd_md_haker      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	toTenCaracters(std::string value)
{
	std::string updatedValue;

	if (value.length() > 10)
	{
		updatedValue.insert(0, value.erase(9, value.length() - 9));
		updatedValue.push_back('.');
		return (updatedValue);
	}
	return (value);
}

void	getValues(PhoneBook *contacts)
{
	std::string getFirst;
	std::string getLast;
	std::string getNick;
	std::string	printedVar[3][3];

	getFirst = contacts->getFirstName();
	getFirst = toTenCaracters(getFirst);

	getLast = contacts->getLastName();
	getLast = toTenCaracters(getLast);

	getNick = contacts->getNickName();
	getNick = toTenCaracters(getNick);

	std::string *val = printedVar[contacts->getIndex() % 3];
	val[0].push_back('|');
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 0)
			val[0].push_back(contacts->getIndex() + '0');
		else
			val[0].push_back(' ');
	}
	val[1].push_back('|');
	for (size_t i = 0; i < 10; i++)
	{
		if (isalpha(getFirst[i]) || isprint(getFirst[i]))
			val[1].push_back(getFirst[i]);
		else
			val[1].push_back(' ');
	}
	val[2].push_back('|');
	for (size_t i = 0; i < 10; i++)
	{
		if (isalpha(getLast[i]) || isprint(getLast[i]))
			val[2].push_back(getLast[i]);
		else
			val[2].push_back(' ');
	}
	val[3].push_back('|');
	for (size_t i = 0; i < 10; i++)
	{
		if (isalpha(getNick[i]) || isprint(getNick[i]))
			val[3].push_back(getNick[i]);
		else
			val[3].push_back(' ');
	}
	val[3].push_back('|');
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << val[i];
	}
	std::cout << std::endl;
}

void	displayData(PhoneBook *contacts, int size)
{
	std::string line;
	std::string inde;

	if (size > 3)
		size = 3;
	std::cout << "|  Index   |First name|Last name |Nick name |" << std::endl;
	for (int i = 0; i < size; i++)
		getValues(&contacts[i % 3]);

	std::cout << "Enter the index :";
	getline(std::cin, line);

	for (int i = 0; i < size; i++)
	{
		inde = contacts[i].getIndex() + '0';
		if (inde == line)
		{
			std::cout << "Your first name is " << contacts[i].getFirstName() << std::endl;
			std::cout << "Your Last name is  " << contacts[i].getLastName() << std::endl;
			std::cout << "Your nick name is " << contacts[i].getNickName() << std::endl;
			std::cout << "Your phone number is " << contacts[i].getPhoneNumber() << std::endl;
			std::cout << "Your Dark Secret is " << contacts[i].gettDarkSecret() << std::endl;
		}
		else
			{std::cout << "We dont have this index " << std::endl; break ;}
	}
}
