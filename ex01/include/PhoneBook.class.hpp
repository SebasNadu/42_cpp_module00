/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:07:10 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/13 16:09:10 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.class.hpp"
#include <limits>
#include <sstream>
#include <stdlib.h>

class PhoneBook {
public:
  PhoneBook() : _index(0){};
  ~PhoneBook(){};

  void addContact(void);
  void searchContact(void);
  void addAllContacts(void);

  static int stoi(std::string &s);
  template <typename T> static std::string to_string(const T &value);

private:
  static int const _maxContacts = 8;
  Contact _contacts[_maxContacts];
  int _index;

  void _printContactsTable(void) const;
  void _searchContactREPL(void);
};

#endif
