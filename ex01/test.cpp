#include <iostream>
#include <string>

const int SCREEN_WIDTH = 112;

void clearScreen() {
  std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the screen
}

void displayWelcomeMessage() {
  clearScreen();
  std::cout << std::string(SCREEN_WIDTH, '=') << std::endl;
  std::cout << "Welcome to the PhoneBook" << std::endl;
  std::cout << std::string(SCREEN_WIDTH, '=') << std::endl;
}

void displayPrompt(const std::string &prompt) {
  std::cout << prompt << std::endl;
}

int main() {
  displayWelcomeMessage();
  displayPrompt("What do you want to do?");
  // Simulate user input and changing prompts
  // You can modify this part according to your user interaction logic
  std::string userInput;
  std::cin >> userInput;
  clearScreen();

  displayPrompt("New prompt message");

  return 0;
}
