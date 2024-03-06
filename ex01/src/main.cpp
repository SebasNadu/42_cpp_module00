/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:43:27 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/06 17:06:45 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/* Goal: Create a program that behaves like a crappy phonebook software
 * Phonebook class has an array of contacts, it can store up to 8 contacts.
 * If the user tries to add a 9th contact, replace the oldest one by the new
 * one. Please note that dynamic allocation is forbidden Contact class stands
 * for a phonebook contact*/

class Contact {
private:
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phonebook;
  std::string darkest_secret;

public:
  Contact(void) { std::cout << "Construct Contact class" << std::endl; }
  ~Contact(void) { std::cout << "Destruct Contact class" << std::endl; }
  void setFirstName(const std::string &fname);
};

class Phonebook {
private:
  Contact contacts[8];
  int index = 0;

public:
  Phonebook(void) { std::cout << "Construct Phonebook class" << std::endl; }
  ~Phonebook(void) { std::cout << "Destruct Phonebook class" << std::endl; }
};

int main() {
  Phonebook my_phonebook;
  return (0);
}
