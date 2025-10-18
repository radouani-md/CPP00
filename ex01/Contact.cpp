#include "PhoneBook.hpp"

bool	checkLineNames(std::string *line)
{
	if (!getline(std::cin, (*line)))
		return (false);
	for (size_t j = 0; j < (line)->length(); j++)
	{
		if (!isprint((*line)[j]))
			return (line->clear(), true);
	}
	return (true);
}

bool	checkLineNum(std::string *line)
{
	if (!getline(std::cin, (*line)))
		return (false);
	for (size_t j = 0; j < (line)->length(); j++)
	{
		if (!isprint((*line)[j]) || isalpha((*line)[j]))
			return (std::cout << "Error ! Invalid input" << std::endl, line->clear(), true);
	}
	return (true);
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
		if (checkLineNames(&line) == false)
			return ;
		if (line.empty())
			continue ;
		contact->setFirstName(line);
	
		std::cout << "Enter your Last name: ";
		if (checkLineNames(&line) == false)
			return ;
		if (line.empty())
			continue ;
		contact->setLastName(line);

		std::cout << "Enter your nick name: ";
		if (checkLineNames(&line) == false)
			return ;
		if (line.empty())
			continue ;
		contact->setNickName(line);

		std::cout << "Enter your phone number: ";
		if (checkLineNum(&line) == false)
			return ;
		if (line.empty())
			continue ;
		contact->setPhoneNumber(line);

		std::cout << "Enter your Dark Secret: ";
		if (checkLineNames(&line) == false)
			return ;
		if (line.empty())
			continue ;
		contact->setDarkSecret(line);
	
		contact->setIndex(index);
		index++;
        len_contact++;
		break ;
	}
}

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

void	fillVar(std::string *val, std::string getMember)
{
	int len = getMember.length();
	if (len < 10)
		(*val).insert(0, 10 - len, ' ');
	(*val).append(getMember);
	(*val).push_back('|');
}

void	getValues(Contact contacts)
{
	std::string getFirst;
	std::string getLast;
	std::string getNick;
	std::string	printedVar[SIZE][4];

	getFirst = contacts.getFirstName();
	getFirst = toTenCaracters(getFirst);

	getLast = contacts.getLastName();
	getLast = toTenCaracters(getLast);

	getNick = contacts.getNickName();
	getNick = toTenCaracters(getNick);

	std::string *val = printedVar[contacts.getIndex() % SIZE];
	val[0].push_back('|');
	val[0].insert(1, 9, ' ');
	val[0].push_back(contacts.getIndex() + '0');
	val[0].push_back('|');
	
	fillVar(&val[1], getFirst);
	fillVar(&val[2], getLast);
	fillVar(&val[3], getNick);
	
	for (size_t i = 0; i < 4; i++){ std::cout << val[i]; }
	std::cout << std::endl;
}

void PhoneBook::displayData()
{
	std::string line;
	bool		isFound = false;
	std::string	str;

	std::cout << "|     Index|First name| Last name| Nick name|" << std::endl;
	for (int i = 0; i < len_contact; i++)
		getValues(contacts[i]);
	
	std::cout << "Enter the index :";
	if (!getline(std::cin, line))
	{
		std::cout << std::endl;
		return ;
	}
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