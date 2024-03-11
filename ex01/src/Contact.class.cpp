/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:08:53 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/11 01:32:00 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.class.hpp"
#include "../include/display.hpp"

std::string Contact::_fieldsName[Contact::FieldsMax] = {
    "index",    "First Name",   "Last Name",
    "Nickname", "Phone Number", "Darkest Secret"};

bool Contact::empty(void) const {
  return this->_fieldsData[this->Index].empty();
}

bool Contact::setData(int id) {
  std::string input;

  if (!this->_fieldsData[this->Index].empty()) {
    while (1) {
      displayMessage("Your PhoneBook is full😭");
      displayMessage(
          "If you want to add a new contact, you must delete the oldest one");
      displayMessage("Do you want to	delete the oldest contact?");
      displayMessage("Enter (y)es or (n)o");
      displayInputSymbol();
      std::getline(std::cin, input);
      if (input == "y" || input == "yes")
        break;
      else if (input == "n" || input == "no")
        return false;
      else if (std::cin.eof())
        return false;
    }
  }
  this->_fieldsData[this->Index] = std::to_string(id + 1);
  for (int i(this->FirstName); i < this->FieldsMax; i++) {
    displayInputLine(this->_fieldsName[i]);
    while (!(std::getline(std::cin, this->_fieldsData[i])) ||
           this->_fieldsData[i].length() == 0) {
      if (std::cin.eof()) {
        return false;
      } else if (this->_fieldsData[i].length() == 0) {
        this->_fieldsData[i].clear();
        displayMessage("Empty information is not allowed");
        displayInputLine(this->_fieldsName[i]);
      }
    }
  }
  return true;
}

void Contact::printTableHeader(void) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("+----------+----------+----------+----------+");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << '\r' << std::setw((SCREEN_WIDTH - 45) / 2) << ' ';
  for (int i(this->Index); i <= this->Nickname; i++) {
    std::cout << '|' << std::setw(10) << std::right << this->_fieldsName[i];
  }
  std::cout << '|' << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("+----------+----------+----------+----------+");
}

void Contact::printTableRow(void) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << '\r' << std::setw((SCREEN_WIDTH - 45) / 2) << ' ';
  for (int i(this->Index); i <= this->Nickname; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << '|';
    if (this->_fieldsData[i].length() > 10) {
      std::cout << std::setw(10) << std::right
                << this->_fieldsData[i].substr(0, 9).append(".");
    } else {
      std::cout << std::setw(10) << std::right << this->_fieldsData[i];
    }
  }
  std::cout << '|' << '\n';
}

void Contact::printContactData(void) const {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << '\n';
  for (int i(this->Index); i < this->FieldsMax; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::string line(this->_fieldsName[i]);
    line.append(": ");
    line.append(this->_fieldsData[i]);
    displayMessage(line);
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << '\n';
}
