#include "Account.hpp"


int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int	Account::getNbAccounts(){ return (_nbAccounts); }
int	Account::getTotalAmount(){ return (_totalAmount); }
int	Account::getNbDeposits(){ return (_totalNbDeposits); }
int	Account::getNbWithdrawals(){ return (_totalNbWithdrawals); }


Account::Account(int initial_deposit)
{
	static int index = 1;

	_accountIndex = index - 1;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
	_totalAmount += _amount;
	_nbAccounts = index;
	index++;
}

void	Account::_displayTimestamp( void )
{
	char		buffer[80];
	time_t		timestamp;

	timestamp = time(NULL);
	struct tm	*localTm = localtime(&timestamp); 
	strftime(buffer, 80, "%Y%m%d_%H%M%S", localTm);
	std::cout << "[" << buffer << "] ";
}


void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(){}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount = _amount + deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	_nbDeposits += 1;
	_totalNbDeposits += _nbDeposits;
	_totalAmount += deposit;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const {return (_amount) ;}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal; 
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals += 1;
	_totalNbWithdrawals += _nbWithdrawals;
	_totalAmount -= withdrawal;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}


Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}
