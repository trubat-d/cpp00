#include "Account.hpp"

#include <time.h>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{

}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += _amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposits:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if(withdrawal < _amount)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "withdrawal:refused" << std::endl;
	return false;
}

int Account::checkAmount() const
{
	return this->_amount;
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" <<  Account::_totalNbDeposits  << ";";
	std::cout << "withdrawals:" <<  Account::_totalNbWithdrawals << std::endl;
}


void Account::_displayTimestamp()
{
	time_t now;
	struct tm *timer;
	time(&now);
	timer = localtime(&now);
	std::cout << "[";
	std::cout << 1900 + timer->tm_year;
	if(timer->tm_mon < 10)
		std::cout << 0 << timer->tm_mon;
	else
		std::cout<< timer->tm_mon;
	if(timer->tm_mday < 10)
		std::cout << 0 << timer->tm_mday;
	else
		std::cout<< timer->tm_mday;
	std::cout << "_";
	if(timer->tm_hour < 10)
		std::cout << 0 << timer->tm_hour;
	else
		std::cout<< timer->tm_hour;
	if(timer->tm_min < 10)
		std::cout << 0 << timer->tm_min;
	else
		std::cout<< timer->tm_min;
	if(timer->tm_sec < 10)
		std::cout << 0 << timer->tm_sec;
	else
		std::cout<< timer->tm_sec;
	std::cout << "] ";
}