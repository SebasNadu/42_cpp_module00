/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:15:54 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/13 16:17:16 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.class.hpp"
#include "../include/display.hpp"

void PhoneBook::addContact(void) {
  clearScreen();
  displayAddTitle();
  if (this->_contacts[this->_index].setData(this->_index) == true) {
    displayMessage("Processing data ...");
    usleep(DELAY_TIME);
    displayMessage("New contact added successfully!");
    this->_index = (this->_index + 1) % this->_maxContacts;
    displayMessage("Press ENTER to return to the main menu");
    displayInputSymbol();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } else if (std::cin.eof()) {
    displayEOFMessage();
    exit(0);
  } else {
    displayMessage("Contact not added");
    displayMessage("Please try again");
    displayMessage("Press ENTER to return to the main menu");
    displayInputSymbol();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  clearScreen();
}

void PhoneBook::addAllContacts(void) {
  std::string data("Contact#");

  clearScreen();
  displayDevMode();
  displayMessage("Adding all contacts ...");
  usleep(DELAY_TIME);
  for (int i(0); i < this->_maxContacts; i++) {
    this->_contacts[i].setAllData(i, data + PhoneBook::to_string(i + 1));
  }
  displayMessage("All contacts added succefully!");
  displayMessage("Press ENTER to return to the main menu");
  displayInputSymbol();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  clearScreen();
}

void PhoneBook::_printContactsTable(void) const {
  this->_contacts[0].printTableHeader();
  for (int i(0); i < this->_maxContacts; i++) {
    if (!this->_contacts[i].empty())
      this->_contacts[i].printTableRow();
  };
  displayMessage("+----------+----------+----------+----------+");
  displayMessage("");
}

void PhoneBook::_searchContactREPL(void) {
  std::string input;
  int const offset(1);

  while (1) {
    displayMessage(
        "Please enter the contact index to display the full information");
    displayMessage("or press ENTER to return to the main menu");
    displayInputSymbol();
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      displayEOFMessage();
      exit(0);
    } else if (input == "") {
      break;
    } else if (input.length() == 1 && input[0] >= '1' && input[0] <= '8' &&
               !this->_contacts[PhoneBook::stoi(input) - offset].empty()) {
      this->_contacts[PhoneBook::stoi(input) - offset].printContactData();
      displayMessage("Press ENTER to return to the main menu");
      displayInputSymbol();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    } else {
      displayMessage("");
      displayMessage("Invalid index");
      displayMessage("");
    }
  }
}

void PhoneBook::searchContact(void) {
  clearScreen();
  displaySearchTitle();
  if (this->_contacts[0].empty()) {
    displayMessage("Your PhoneBook is empty");
    displayMessage("Add a new contact to start using the search feature");
    displayMessage("Press ENTER to return to the main menu");
    displayInputSymbol();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
  };
  this->_printContactsTable();
  this->_searchContactREPL();
  clearScreen();
}

int PhoneBook::stoi(std::string &s) {
  int i;
  std::istringstream(s) >> i;
  return i;
}

template <typename T> std::string PhoneBook::to_string(const T &value) {
  std::ostringstream oss;

  oss << value;
  return oss.str();
}
