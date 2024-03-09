/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:07:10 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/09 19:21:25 by sebasnadu        ###   ########.fr       */
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
  static int const _maxContacts = 8;
  Contact _contacts[_maxContacts];
  int _index;
};

#endif
