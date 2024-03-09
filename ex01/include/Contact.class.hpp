/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:56:31 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/08 21:07:40 by sebasnadu        ###   ########.fr       */
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

  bool set_contact(void);
  /* void get_contact(int index) const; */

private:
  enum Fields { firstName, lastName, nickname, phoneNumber, darkestSecret };
  static std::string _fieldsName[5];
  std::string _fieldsData[5];
};

#endif
