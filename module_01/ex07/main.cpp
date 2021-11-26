/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 18:51:21 by idonado       #+#    #+#                 */
/*   Updated: 2020/11/25 21:13:03 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	// Checks if we have correct number of arguements.
	if (argc != 4)
	{
		std::cout << "\033[31m\033[1mWrong number of parameters\033[0m" << std::endl;
		std::cout << "You must execute the program using the following syntax; \033[97m" 
		<< std::endl << "./replace FILENAME string1 string2\033[39m" << std::endl;
		return (0);
	}

	// Creating necessary variables, storing filename, str1, str2 to C++ strings.
	// Also setting the result's filename.
	std::string		filename(argv[1]);
	std::string		str1(argv[2]);
	std::string		str2(argv[3]);
	std::string		output_filename = filename + ".replace";

	// Creating a filestream for reading from file & another one for writing.
	std::ifstream	read(filename.c_str());

	// Checks if reading filestream was successfull, if file exists for example.
	if (!(read.is_open()))
	{
		std::cout << "\033[31m\033[1mFile requested does not exist!\033[0m" << std::endl;
		std::cout << "You must execute the program using the following syntax; \033[97m" 
		<< std::endl << "./replace FILENAME string1 string2\033[39m" << std::endl;
		return (0);
	}

	// Creating a filestream for writing into file.
	std::ofstream	write(output_filename.c_str());
	// Checks if input filestream was successfull, although it should be ok always.
	if (!(write.is_open()))
	{
		std::cout << "\033[31m\033[1mUnexpected error!\033[0m" << std::endl;
		return (0);
	}

	// Variable for finding position of string1 and variable for string length.
	std::size_t	i;
	std::size_t len = str1.length();
	// A Temp string for editing and copying content to the writing filestream.
	std::string		temp;

	// Loop until all lines have been read.
	while (getline(read, temp))
	{
		// Loop until substring is not found in string.
		while ((i = temp.find(str1)) != std::string::npos)
		{
			temp = temp.replace(i, len, str2);
		}
		write << temp << std::endl;
	}

	read.close();
	write.close();
	return (0);
}
