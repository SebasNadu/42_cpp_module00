/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:15:54 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/11 01:19:24 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.class.hpp"
#include "../include/display.hpp"

void PhoneBook::addContact(void) {
  clearScreen();
  displayAddTitle();
  if (this->_contacts[this->_index].setData(this->_index) == true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Processing data ...");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    displayMessage("New contact added successfully!");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    this->_index = (this->_index + 1) % this->_maxContacts;
    displayMessage("Press ENTER to return to the main menu");
    displayInputSymbol();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  } else if (std::cin.eof()) {
    displayEOFMessage();
    std::exit(0);
  } else {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Contact not added");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Please try again");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Press ENTER to return to the main menu");
    displayInputSymbol();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  clearScreen();
}

void PhoneBook::_printContactsTable(void) const {
  this->_contacts[0].printTableHeader();
  for (int i(0); i < this->_maxContacts; i++) {
    if (!this->_contacts[i].empty())
      this->_contacts[i].printTableRow();
  };
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("+----------+----------+----------+----------+");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("");
}

void PhoneBook::searchContact(void) {
  std::string input;
  int const offset(1);

  clearScreen();
  displaySearchTitle();
  if (this->_contacts[0].empty()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Your PhoneBook is empty");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Add a new contact to start using the search feature");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Press ENTER to return to the main menu");
    displayInputSymbol();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return;
  };
  this->_printContactsTable();
  while (1) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage(
        "Please enter the contact index to display the full information");
    displayMessage("or press ENTER to return to the main menu");
    displayInputSymbol();
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      displayEOFMessage();
      std::exit(0);
    } else if (input == "") {
      break;
    } else if (input.length() == 1 && input[0] >= '1' && input[0] <= '8' &&
               !this->_contacts[std::stoi(input) - offset].empty()) {
      this->_contacts[std::stoi(input) - offset].printContactData();
      displayMessage("Press ENTER to return to the main menu");
      displayInputSymbol();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    } else {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::cout << std::setw(SCREEN_WIDTH) << ' ' << '\n';
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      displayMessage("Invalid index");
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      displayMessage("");
    }
  }
  clearScreen();
}
