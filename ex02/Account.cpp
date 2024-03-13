/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:27:40 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/13 14:18:09 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  Account::_nbAccounts++;
  Account::_totalAmount += this->_amount;
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created" << std::endl;
}

void Account::_displayTimestamp() {
  std::time_t timestamp = std::time(nullptr);
  std::tm *local = localtime(&timestamp);

  std::cout << '[' << std::put_time(local, "%Y%m%d_%H%M%S") << "] ";
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts()
            << ";total:" << Account::getTotalAmount()
            << ";deposits:" << Account::getNbDeposits()
            << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

int Account::getNbAccounts(void) { return Account::_nbAccounts; }

int Account::getTotalAmount(void) { return Account::_totalAmount; }

int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  this->_nbDeposits++;
  this->_amount += deposit;
  Account::_totalNbDeposits++;
  Account::_totalAmount += deposit;
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
  if (withdrawal > this->_amount) {
    std::cout << ";withdrawal:refused" << std::endl;
    return (false);
  }
  this->_nbWithdrawals++;
  this->_amount -= withdrawal;
  Account::_totalNbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return (true);
}

int Account::checkAmount(void) const { return this->_amount; }

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
  Account::_nbAccounts--;
  Account::_totalAmount -= this->_amount;
}
