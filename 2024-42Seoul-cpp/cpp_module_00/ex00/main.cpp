/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yegkim <yegkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:23:50 by yegkim            #+#    #+#             */
/*   Updated: 2024/04/02 13:26:13 by yegkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

void	printUpper(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); i++) {
		std::cout << static_cast<char>(std::toupper(str[i]));
	}
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else
	{
		for (int i = 1; argv[i]; i++){
			printUpper(argv[i]);
		}
		std::cout << std::endl;
	}
	return (0);
}