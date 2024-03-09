/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:08:53 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/09 23:41:11 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.class.hpp"
#include "../include/display.hpp"

std::string Contact::_fieldsName[Contact::fieldsMax] = {
    "First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};

bool Contact::setData(int id) {
  std::string input;

  if (!this->_fieldsData[0].empty()) {
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
  for (int i = this->firstName; i < this->fieldsMax; i++) {
    this->id = id + 1;
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
