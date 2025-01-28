/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:08:03 by ojacobs           #+#    #+#             */
/*   Updated: 2025/01/27 18:30:56 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// Static variable definitions (initializing static variables)
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    // Update static variables
    _nbAccounts++;
    _totalAmount += _amount;

    // Display account creation info
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;	
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() <<";total:" << getTotalAmount() << ";deposits:"
	<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() <<'\n';
}
void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit
	<< ";amount:" << checkAmount() << ";nb_deposits:" << ++_nbDeposits << '\n';
	_totalNbDeposits++;
	_totalAmount+=deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
   int p_amount = checkAmount();
	if(withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << '\n';
		return false;
	}
	else
	{
		_amount -= withdrawal;
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal
		<< ";amount:" << checkAmount() << ";nb_withdrawals:" << ++_nbWithdrawals << '\n';
		_totalNbWithdrawals++;
		_totalAmount-= withdrawal;
		return true;
	}
	
}
int	Account::checkAmount( void ) const
{
	return _amount;
}
void Account::displayStatus( void ) const
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals <<'\n';
}

void Account::_displayTimestamp(void) {
    // Get current time
    std::time_t now = std::time(NULL);
    std::tm *local_time = std::localtime(&now);

    // Format the time as [YYYYMMDD_HHMMSS]
    std::cout << "[" << (local_time->tm_year + 1900) // Year since 1900
              << ((local_time->tm_mon + 1) < 10 ? "0" : "") <<  local_time->tm_mon + 1     // Month (tm_mon is 0-based)
              << ((local_time->tm_mday < 10 ? "0" : "") )  << local_time->tm_mday    // Day of the month
              << "_"
              << (local_time->tm_hour < 10 ? "0" : "") << local_time->tm_hour // Add leading zero for hour
              << (local_time->tm_min < 10 ? "0" : "")  << local_time->tm_min  // Add leading zero for minute
              << (local_time->tm_sec < 10 ? "0" : "")  << local_time->tm_sec  // Add leading zero for second
              << "] ";
}

Account::~Account()
{
	_displayTimestamp(); 
	std::cout << "index:" <<_accountIndex <<";amount:"
	<<_amount <<";closed\n"; 
}