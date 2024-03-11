/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:56:31 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/11 00:29:18 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact {
public:
  Contact(void){};
  ~Contact(void){};

  bool empty(void) const;
  bool setData(int id);
  void printTableHeader(void) const;
  void printTableRow(void) const;
  void printContactData(void) const;

private:
  enum Fields {
    Index,
    FirstName,
    LastName,
    Nickname,
    PhoneNumber,
    DarkestSecret,
    FieldsMax
  };
  static std::string _fieldsName[FieldsMax];
  std::string _fieldsData[FieldsMax];
};

#endif
