/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:19:33 by mradouan          #+#    #+#             */
/*   Updated: 2025/10/03 18:20:32 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	checkLineNames(std::string *line)
{
	getline(std::cin, (*line));
	for (size_t j = 0; j < (line)->length(); j++)
	{
		if (!isprint((*line)[j]))
			return ("");
	}
	return ((*line));
}

std::string	checkLineNum(std::string *line)
{
	getline(std::cin, (*line));
	for (size_t j = 0; j < (line)->length(); j++)
	{
		if (!isprint((*line)[j]) || isalpha((*line)[j]))
			return (std::cout << "Error ! Invalid input" << std::endl, "");
	}
	return ((*line));
}

void	PhoneBook::addNewContact()
{
	std::string line;
	static int	index = 0;
    Contact *contact = &contacts[index % SIZE];

	while (1)
	{
        if (len_contact >= SIZE - 1)
            len_contact = SIZE - 1;
		std::cout << "Enter your first name: ";
		line = checkLineNames(&line);
		if (line.empty())
			continue ;
		contact->setFirstName(line);
		std::cout << "Enter your Last name: ";
		line = checkLineNames(&line);
		if (line.empty())
			continue ;
		contact->setLastName(line);

		std::cout << "Enter your nick name: ";
		line = checkLineNames(&line);
		if (line.empty())
			continue ;
		contact->setNickName(line);

		std::cout << "Enter your phone number: ";
		line = checkLineNum(&line);
		if (line.empty())
			continue ;
		contact->setPhoneNumber(line);

		std::cout << "Enter your Dark Secret: ";
		line = checkLineNames(&line);
		if (line.empty())
			continue ;
		contact->setDarkSecret(line);
		contact->setIndex(index);
		index++;
        len_contact++;
		break ;
	}
}
/*
    /////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
*/
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

void	getValues(Contact contacts)
{
	std::string getFirst;
	std::string getLast;
	std::string getNick;
	std::string	printedVar[SIZE][3];

	getFirst = contacts.getFirstName();
	getFirst = toTenCaracters(getFirst);

	getLast = contacts.getLastName();
	getLast = toTenCaracters(getLast);

	getNick = contacts.getNickName();
	getNick = toTenCaracters(getNick);

	std::string *val = printedVar[contacts.getIndex() % SIZE];
	val[0].push_back('|');
   
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 0)
			val[0].push_back(contacts.getIndex() + '0');
		else
			val[0].push_back(' ');
	}
	val[1].push_back('|'); 
    for (size_t i = 0; i < 10; i++)
	{
        char safeCh = (i < getFirst.length()) ? getFirst[i] : ' ';
		if (isalpha(safeCh) || isprint(safeCh))
			val[1].push_back(safeCh);
		else
			val[1].push_back(' ');
	}
	val[2].push_back('|');
	for (size_t i = 0; i < 10; i++)
	{
        char safeCh = (i < getLast.length()) ? getLast[i] : ' ';
		if (isalpha(safeCh) || isprint(safeCh))
			val[2].push_back(safeCh);
		else
			val[2].push_back(' ');
	}
	val[3].push_back('|');
	for (size_t i = 0; i < 10; i++)
	{
        char safeCh = (i < getNick.length()) ? getNick[i] : ' ';
		if (isalpha(safeCh) || isprint(safeCh))
			val[3].push_back(safeCh);
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

void PhoneBook::displayData()
{
	std::string line;
	bool		isFound = false;
	std::string	str;

	std::cout << "|  Index   |First name|Last name |Nick name |" << std::endl;
	for (int i = 0; i < len_contact; i++)
		getValues(contacts[i]);
	
	std::cout << "Enter the index :";
	getline(std::cin, line);

	for (int i = 0; i < len_contact; i++)
	{
        str = contacts[i].getIndex() + '0';
		if (str == line)
		{
			isFound = true;
			std::cout << "Your first name is " << contacts[i].getFirstName() << std::endl;
			std::cout << "Your Last name is  " << contacts[i].getLastName() << std::endl;
			std::cout << "Your nick name is " << contacts[i].getNickName() << std::endl;
			std::cout << "Your phone number is " << contacts[i].getPhoneNumber() << std::endl;
			std::cout << "Your Dark Secret is " << contacts[i].gettDarkSecret() << std::endl;
            break ;
		}
	}
	if (isFound == false)
		std::cout << "We dont have this index " << std::endl;
}