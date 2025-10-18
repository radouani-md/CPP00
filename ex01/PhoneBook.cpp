#include "PhoneBook.hpp"


void	Contact::setFirstName(std::string fName)
{
	firstName = fName;
}

void	Contact::setLastName(std::string lName)
{
	lastName = lName;
}

void	Contact::setNickName(std::string nName)
{
	nickName = nName;
}

void	Contact::setDarkSecret(std::string dSecret)
{
	darkSecret = dSecret;
}

void	Contact::setPhoneNumber(std::string pNum)
{
	phoneNum = pNum;
}
void	Contact::setIndex(int ind)
{
	index = ind;
}
void	PhoneBook::initialize_len(void){ len_contact = 0; }

std::string Contact::getFirstName() { return (firstName); }
std::string Contact::getLastName() { return (lastName); }
std::string Contact::getNickName() { return (nickName); }
std::string Contact::gettDarkSecret() { return (darkSecret); }
std::string Contact::getPhoneNumber() { return (phoneNum); }
int			Contact::getIndex() { return (index); }