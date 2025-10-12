/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:42:48 by mradouan          #+#    #+#             */
/*   Updated: 2025/10/11 15:39:40 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook contacts;
	std::string line;

	int count = 0;
	while (true)
	{
		if (!getline(std::cin, line))
			break ;
		if (line == "ADD")
		{
			contacts.addNewContact();
			count++;
		}
		else if (line == "SEARCH")
		{
			contacts.displayData();
		}
		else if (line == "EXIT")
			break ;
	}
	
}
