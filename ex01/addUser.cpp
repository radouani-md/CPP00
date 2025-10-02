/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addUser.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd_md_haker <rd_md_haker@student.42.fr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 09:11:34 by rd_md_haker       #+#    #+#             */
/*   Updated: 2025-10-02 09:11:34 by rd_md_haker      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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

void	addNewContact(PhoneBook *contact)
{
	std::string line;
	static int	index = 0;
	bool		isDone = false;

	while (isDone == false)
	{
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
		isDone = true;
	}
}
