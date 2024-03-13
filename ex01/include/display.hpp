/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:22:08 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/03/13 15:23:45 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "colors.hpp"
#include <iomanip>
#include <iostream>
#include <unistd.h>

#define SCREEN_WIDTH 100
#define DELAY_TIME 1000

void displayWelcomeMessage(void);
void displayPrompt(void);
void displayEOFMessage(void);
void displayExitMessage(void);
void displayInstructionMessage(void);
void displayAddTitle(void);
void displaySearchTitle(void);
void displayInputSymbol(void);
void clearScreen(void);
void displayMessage(const std::string &msg);
void displayInputLine(std::string &field);
void displayDevMode(void);

#endif
