/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:42:48 by mradouan          #+#    #+#             */
/*   Updated: 2025/09/29 14:04:25 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	std::string line;
	PhoneBook contacts[3]; // To 8
	int count = 0;

	while (getline(std::cin, line))
	{
		if (line == "ADD")
		{
			addNewContact(&contacts[count % 3]);
			count++;
		}
		else if (line == "SEARCH")
		{
			displayData(contacts, count);
		}
		else if (line == "EXIT")
			break ;
	}
	std::cout << std::endl;
	
}
