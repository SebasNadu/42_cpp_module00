#include <cstddef> // for std
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		int n (3);
		std::cout << sizeof(std::size_t) << '\n';
		std::cout << n << '\n';
		std::cout << av[1] << std::endl;
	}
	return (0);
}
