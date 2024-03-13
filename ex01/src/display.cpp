/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:35 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/13 16:16:50 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/display.hpp"

void clearScreen(void) { std::cout << CRESET << "\033[2J\033[1;1H" << BLUB; }

void displayWelcomeMessage(void) {
  clearScreen();
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  usleep(DELAY_TIME);
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
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
}

void displayMessage(const std::string &msg) {
  std::string message(msg);
  int padding((SCREEN_WIDTH - message.length()) / 2);

  usleep(DELAY_TIME);
  std::cout << std::setw(padding + message.length()) << std::right << message;
  std::cout << std::setw(SCREEN_WIDTH - padding - message.length())
            << std::right << ' ' << std::endl;
}

void displayInputSymbol(void) {
  int padding((SCREEN_WIDTH - 3) / 2);

  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << "\r" << std::setw(padding) << BMAG << " > " << CRESET << BLUB;
}

void displayInputLine(std::string &field) {
  std::string message("Please enter the ");
  message.append(field);
  message.append(": ");
  int padding((SCREEN_WIDTH - (message.length() + 10)) / 2);

  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << '\r' << std::setw(padding + message.length()) << std::right
            << message;
}

void displayPrompt(void) {

  usleep(DELAY_TIME);
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*                 Main menu                 *");
  displayMessage("*********************************************");
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << '\n';
  displayMessage("What do you want to do?");
  displayMessage("ADD | SEARCH | EXIT");
  displayMessage("");
  displayInputSymbol();
}

void displayGoodbyeMessage(void) {
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  usleep(DELAY_TIME);
  std::cout << "\
                 ██████╗  ██████╗  ██████╗ ██████╗     ██████╗ ██╗   ██╗███████╗██╗                 \n\
                ██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗    ██╔══██╗╚██╗ ██╔╝██╔════╝██║                 \n\
                ██║  ███╗██║   ██║██║   ██║██║  ██║    ██████╔╝ ╚████╔╝ █████╗  ██║                 \n\
                ██║   ██║██║   ██║██║   ██║██║  ██║    ██╔══██╗  ╚██╔╝  ██╔══╝  ╚═╝                 \n\
                ╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝    ██████╔╝   ██║   ███████╗██╗                 \n\
                 ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝     ╚═════╝    ╚═╝   ╚══════╝╚═╝                 "
            << '\n';
  usleep(DELAY_TIME);
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
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displayAddTitle(void) {
  usleep(DELAY_TIME);
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*              Add New Contact              *");
  displayMessage("*********************************************");
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displaySearchTitle(void) {
  usleep(DELAY_TIME);
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*              Search Contacts              *");
  displayMessage("*********************************************");
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displayDevMode(void) {
  usleep(DELAY_TIME);
  std::cout << '\r' << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*                 Dev Mode                  *");
  displayMessage("*********************************************");
  usleep(DELAY_TIME);
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}
