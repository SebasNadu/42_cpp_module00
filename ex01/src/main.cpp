/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:43:27 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/11 13:25:21 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.class.hpp"
#include "../include/display.hpp"

#ifdef DEV
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
    } else if (input == "ADD+") {
      phoneBook.addAllContacts();
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
#else
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
#endif
