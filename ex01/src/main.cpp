/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:43:27 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/08 14:56:24 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.class.hpp"
#include "../include/display.hpp"

/* Goal: Create a program that behaves like a crappy phonebook software
 * Phonebook class has an array of contacts, it can store up to 8 contacts.
 * If the user tries to add a 9th contact, replace the oldest one by the new
 * one. Please note that dynamic allocation is forbidden Contact class stands
 * for a phonebook contact*/

int main(void) {
  std::string input;
  PhoneBook phoneBook;

  displayWelcomeMessage();
  while (displayPrompt(), std::getline(std::cin, input)) {
    if (input == "EXIT") {
      displayExitMessage();
      break;
    } else if (input == "ADD") {
      phoneBook.addContact();
    } else if (input == "SEARCH") {
      phoneBook.searchContact();
    } else if (std::cin.eof()) {
      break;
    } else {
      displayInstructionMessage();
    }
    std::cin.clear();
  }
  if (std::cin.eof())
    displayEOFMessage();
  return (0);
}
