/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:56:31 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/09 19:54:15 by sebasnadu        ###   ########.fr       */
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

  int id;
  bool setData(int id);
  /* void getData(int index) const; */

private:
  enum Fields {
    firstName,
    lastName,
    nickname,
    phoneNumber,
    darkestSecret,
    fieldsMax
  };
  static std::string _fieldsName[fieldsMax];
  std::string _fieldsData[fieldsMax];
};

#endif
