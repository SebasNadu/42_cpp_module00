/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:02:54 by sebasnadu         #+#    #+#             */
/*   Updated: 2024/02/18 14:32:45 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void scream(char **av) {
  while (*++av) {
    for (char *tmp(*av); *tmp; ++tmp)
      *tmp = std::toupper(*tmp);
    std::cout << *av;
    if (*(av + 1) != NULL)
      std::cout << ' ';
  }
  std::cout << std::endl;
}

int main(int ac, char **av) {
  if (ac == 1)
    std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else
    scream(av);
  return (0);
}
