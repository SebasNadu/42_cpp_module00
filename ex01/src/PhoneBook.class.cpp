/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:15:54 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/08 21:37:05 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.class.hpp"
#include "../include/display.hpp"

void PhoneBook::addContact(void) { displayAddTitle(); }

void PhoneBook::searchContact(void) {
  std::cout << "Inside searchContact" << std::endl;
}
