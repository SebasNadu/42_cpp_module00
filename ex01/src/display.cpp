/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:35 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/11 01:20:07 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/display.hpp"

void clearScreen(void) { std::cout << CRESET << "\033[2J\033[1;1H" << BLUB; }

void displayWelcomeMessage(void) {
  clearScreen();
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "\
 ██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗    ████████╗ ██████╗                \n\
 ██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝    ╚══██╔══╝██╔═══██╗               \n\
 ██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗         ██║   ██║   ██║               \n\
 ██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝         ██║   ██║   ██║               \n\
 ╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗       ██║   ╚██████╔╝               \n\
  ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝       ╚═╝    ╚═════╝                \n\
 ███╗   ███╗██╗   ██╗     █████╗ ██╗    ██╗███████╗███████╗ ██████╗ ███╗   ███╗███████╗             \n\
 ████╗ ████║╚██╗ ██╔╝    ██╔══██╗██║    ██║██╔════╝██╔════╝██╔═══██╗████╗ ████║██╔════╝             \n\
 ██╔████╔██║ ╚████╔╝     ███████║██║ █╗ ██║█████╗  ███████╗██║   ██║██╔████╔██║█████╗               \n\
 ██║╚██╔╝██║  ╚██╔╝      ██╔══██║██║███╗██║██╔══╝  ╚════██║██║   ██║██║╚██╔╝██║██╔══╝               \n\
 ██║ ╚═╝ ██║   ██║       ██║  ██║╚███╔███╔╝███████╗███████║╚██████╔╝██║ ╚═╝ ██║███████╗             \n\
 ╚═╝     ╚═╝   ╚═╝       ╚═╝  ╚═╝ ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝             \n\
  █████╗  ██████╗     ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗ \n\
 ██╔══██╗██╔═████╗    ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝ \n\
 ╚█████╔╝██║██╔██║    ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝  \n\
 ██╔══██╗████╔╝██║    ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗  \n\
 ╚█████╔╝╚██████╔╝    ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗ \n\
  ╚════╝  ╚═════╝     ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ \
	" << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void displayMessage(const std::string &msg) {
  std::string message(msg);
  int padding((SCREEN_WIDTH - message.length()) / 2);

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(padding + message.length()) << std::right << message;
  std::cout << std::setw(SCREEN_WIDTH - padding - message.length())
            << std::right << ' ' << std::endl;
}

void displayInputSymbol(void) {
  int padding((SCREEN_WIDTH - 3) / 2);

  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << "\r" << std::setw(padding) << BMAG << " > " << CRESET << BLUB;
}

void displayInputLine(std::string &field) {
  std::string message("Please enter the ");
  message.append(field);
  message.append(": ");
  int padding((SCREEN_WIDTH - (message.length() + 10)) / 2);

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << '\r' << std::setw(padding + message.length()) << std::right
            << message;
}

void displayPrompt(void) {

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*                 Main menu                 *");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("What do you want to do?");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("ADD | SEARCH | EXIT");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayInputSymbol();
}

void displayGoodbyeMessage(void) {
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "\
                 ██████╗  ██████╗  ██████╗ ██████╗     ██████╗ ██╗   ██╗███████╗██╗                 \n\
                ██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗    ██╔══██╗╚██╗ ██╔╝██╔════╝██║                 \n\
                ██║  ███╗██║   ██║██║   ██║██║  ██║    ██████╔╝ ╚████╔╝ █████╗  ██║                 \n\
                ██║   ██║██║   ██║██║   ██║██║  ██║    ██╔══██╗  ╚██╔╝  ██╔══╝  ╚═╝                 \n\
                ╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝    ██████╔╝   ██║   ███████╗██╗                 \n\
                 ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝     ╚═════╝    ╚═╝   ╚══════╝╚═╝                 "
            << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << " " << CRESET << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void displayEOFMessage(void) {
  std::cout << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("You pressed ^D, the program will exit now...");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("I hope you had a great time using this program...");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayGoodbyeMessage();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
void displayExitMessage(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("You typed EXIT, the program will exit now...");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("I hope you had a great time using this program...");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayGoodbyeMessage();
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void displayInstructionMessage(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage(
      "You typed an invalid command, please type on of the following:");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*___________________________________________*");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("|                                           |");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("| ADD: Add a new contact in your phonebook. |");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("| SEARCH: Shows you all your contacts.      |");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("| EXIT: Quit your favorite phonebook.       |");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*___________________________________________*");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void displayAddTitle(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*              Add New Contact              *");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void displaySearchTitle(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*              Search Contacts              *");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
