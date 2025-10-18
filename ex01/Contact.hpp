#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
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