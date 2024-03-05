/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:43:27 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/02/19 15:36:35 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/* Goal: Create a program that behaves like a crappy phonebook software
 * Phonebook class has an array of contacts, it can store up to 8 contacts.
 * If the user tries to add a 9th contact, replace the oldest one by the new one.
 * Please note that dynamic allocation is forbidden
 * Contact class stands for a phonebook contact*/
int	main() {
	td::string hello = "Hello, World!";
	std::cout << hello << std::endl;
	std::cout << hello.length() << std::endl;
	std::cout << hello.size() << std::endl;
	std::cout << hello[0] << std::endl;
	return (0);
}
