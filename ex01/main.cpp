#include "PhoneBook.hpp"

int main()
{
	PhoneBook contacts;
	std::string line;

	contacts.initialize_len();
	int count = 0;
	while (true)
	{
		std::cout << "Enter one from these : ADD | SEARCH | EXIT" << std::endl; 
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
