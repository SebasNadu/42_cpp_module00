/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:19:35 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/08 21:37:30 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/display.hpp"

void clearScreen(void) {
  std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the screen
}

void displayWelcomeMessage(void) {
  clearScreen();
  std::cout << BLUB << std::setw(SCREEN_WIDTH) << " " << '\n';
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
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
}

void displayMessage(const std::string &msg) {
  std::string message(msg);
  int padding((SCREEN_WIDTH - message.length()) / 2);

  std::cout << std::setw(padding + message.length()) << std::right << message;
  std::cout << std::setw(SCREEN_WIDTH - padding - message.length())
            << std::right << ' ' << std::endl;
}

void displayPrompt(void) {
  displayMessage("What do you want to do?");
  displayMessage("ADD | SEARCH | EXIT");
  displayMessage("");
  std::cout << std::setw(SCREEN_WIDTH) << ' ';
  std::cout << "\r" << BMAG << " > " << CRESET << BLUB;
}

void displayGoodbyeMessage(void) {
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  std::cout << "\
                 ██████╗  ██████╗  ██████╗ ██████╗     ██████╗ ██╗   ██╗███████╗██╗                 \n\
                ██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗    ██╔══██╗╚██╗ ██╔╝██╔════╝██║                 \n\
                ██║  ███╗██║   ██║██║   ██║██║  ██║    ██████╔╝ ╚████╔╝ █████╗  ██║                 \n\
                ██║   ██║██║   ██║██║   ██║██║  ██║    ██╔══██╗  ╚██╔╝  ██╔══╝  ╚═╝                 \n\
                ╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝    ██████╔╝   ██║   ███████╗██╗                 \n\
                 ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝     ╚═════╝    ╚═╝   ╚══════╝╚═╝                 "
            << '\n';
  std::cout << std::setw(SCREEN_WIDTH) << " " << CRESET << std::endl;
}

void displayEOFMessage(void) {
  std::cout << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("You pressed ^D, the program will exit now...");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("I hope you had a great time using this program...");
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  displayGoodbyeMessage();
  std::this_thread::sleep_for(std::chrono::seconds(1));
}
void displayExitMessage(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("You typed EXIT, the program will exit now...");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("I hope you had a great time using this program...");
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  displayGoodbyeMessage();
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void displayInstructionMessage(void) {
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage(
      "You typed an invalid command, please type on of the following:");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("*___________________________________________*");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("|                                           |");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("| ADD: Add a new contact in your phonebook. |");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("| SEARCH: Shows you all your contacts.      |");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("| EXIT: Quit your favorite phonebook.       |");
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  displayMessage("*___________________________________________*");
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displayAddTitle(void) {
  clearScreen();
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*              Add New Contact              *");
  displayMessage("*********************************************");
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}

void displaySearchTitle(void) {
  clearScreen();
  std::cout << std::setw(SCREEN_WIDTH) << " " << '\n';
  displayMessage("*********************************************");
  displayMessage("*              Search Contacts              *");
  displayMessage("*********************************************");
  std::cout << std::setw(SCREEN_WIDTH) << ' ' << std::endl;
}
