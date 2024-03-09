/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:07:10 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/08 20:01:45 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.class.hpp"

class PhoneBook {
public:
  PhoneBook() : _index(0){};
  ~PhoneBook(){};

  void addContact(void);
  void searchContact(void);

private:
  Contact _contacts[8];
  int _index;
  static int const _maxContacts = 8;
};

#endif
