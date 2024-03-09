/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:15:54 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/09 23:45:27 by sebasnadu        ###   ########.fr       */
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
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    this->_index = (this->_index + 1) % this->_maxContacts;
  } else if (std::cin.eof()) {
    displayEOFMessage();
    std::exit(0);
  } else {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    displayMessage("Contact not added");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
  }
  std::this_thread::sleep_for(std::chrono::seconds(1));
  clearScreen();
}

void PhoneBook::searchContact(void) {
  std::cout << "Inside searchContact" << std::endl;
}
