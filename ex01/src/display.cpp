/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:35 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/11 12:50:00 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/display.hpp"

void clearScreen(void) { std::cout << CRESET << "\033[2J\033[1;1H" << BLUB; }

void displayWelcomeMessage(void) {
  clearScreen();
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
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
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
}

void displayMessage(const std::string &msg) {
  std::string message(msg);
  int padding((SCREEN_WIDTH - message.length()) / 2);

  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(padding + message.length()) << std::right << message;
  std::cout << std::setw(SCREEN_WIDTH - padding - message.length())
            << std::right << ' ' << std::endl;
}

void displayInputSymbol(void) {
  int padding((SCREEN_WIDTH - 3) / 2);

  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << "\r" << std::setw(padding) << BMAG << " > " << CRESET << BLUB;
}

void displayInputLine(std::string &field) {
  std::string message("Please enter the ");
  message.append(field);
  message.append(": ");
  int padding((SCREEN_WIDTH - (message.length() + 10)) / 2);

  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << '\r' << std::setw(padding + message.length()) << std::right
            << message;
}

void displayPrompt(void) {

  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*                 Main menu                 *");
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << '\n';
  displayMessage("What do you want to do?");
  displayMessage("ADD | SEARCH | EXIT");
  displayMessage("");
  displayInputSymbol();
}

void displayGoodbyeMessage(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << "\
                 ██████╗  ██████╗  ██████╗ ██████╗     ██████╗ ██╗   ██╗███████╗██╗                 \n\
                ██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗    ██╔══██╗╚██╗ ██╔╝██╔════╝██║                 \n\
                ██║  ███╗██║   ██║██║   ██║██║  ██║    ██████╔╝ ╚████╔╝ █████╗  ██║                 \n\
                ██║   ██║██║   ██║██║   ██║██║  ██║    ██╔══██╗  ╚██╔╝  ██╔══╝  ╚═╝                 \n\
                ╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝    ██████╔╝   ██║   ███████╗██╗                 \n\
                 ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝     ╚═════╝    ╚═╝   ╚══════╝╚═╝                 "
            << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << " " << CRESET << std::endl;
}

void displayEOFMessage(void) {
  std::cout << '\n';
  displayMessage("You pressed ^D, the program will exit now...");
  displayMessage("I hope you had a great time using this program...");
  displayGoodbyeMessage();
}

void displayExitMessage(void) {
  displayMessage("You typed EXIT, the program will exit now...");
  displayMessage("I hope you had a great time using this program...");
  displayGoodbyeMessage();
}

void displayInstructionMessage(void) {
  displayMessage(
      "You typed an invalid command, please type on of the following:");
  displayMessage("*___________________________________________*");
  displayMessage("|                                           |");
  displayMessage("| ADD: Add a new contact in your phonebook. |");
  displayMessage("| SEARCH: Shows you all your contacts.      |");
  displayMessage("| EXIT: Quit your favorite phonebook.       |");
  displayMessage("*___________________________________________*");
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displayAddTitle(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*              Add New Contact              *");
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displaySearchTitle(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*              Search Contacts              *");
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displayDevMode(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*                 Dev Mode                  *");
  displayMessage("*********************************************");
  std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_TIME));
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}
