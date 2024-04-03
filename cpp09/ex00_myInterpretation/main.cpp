/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:32:36 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/02 16:02:21 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// static float	conFloat;

void	fillCsvMap(std::multimap<std::string, float> &csvFile)
{
	std::ifstream	file("data.csv");
	std::string	line;
	std::stringstream	reader;
	float	coinValue;

	std::getline(file, line);
	if (!file.is_open())
	{
		std::cerr<<"Error could not open file "<<std::endl;
		return ;
	}
	while (std::getline(file, line))
	{
		reader.clear();
		reader.str(line);
		std::string			date;
		std::string			bitCoinValue;

		if (std::getline(reader, date, ',') && std::getline(reader, bitCoinValue, ','))
		{
			std::stringstream	converter(bitCoinValue);
			converter >> coinValue;
			csvFile.insert(std::make_pair(date, coinValue));
		}
	}
	file.close();
}

void	fillUserMap(std::multimap<std::string, float> &userFile, char **argv)
{
	std::ifstream		file(argv[1]);
	std::string			line;
	std::stringstream	reader;
	float	coinValue;

	std::getline(file, line);

	if (!file.is_open())
	{
		throw std::runtime_error("Error could not open file");
	}
	while (std::getline(file, line))
	{
		reader.clear();
		reader.str(line);
		std::string			date;
		std::string			bitCoinValue;

		if (std::getline(reader, date, '|') && std::getline(reader, bitCoinValue, '|'))
		{
			std::stringstream	converter(bitCoinValue);
			converter >> coinValue;
			date.erase(date.size() - 1);
			userFile.insert(std::make_pair(date, coinValue));
		}
		else
			std::cout<<"Pair not valid "<<date<<std::endl;
	}
	file.close();
}

int	main(int argc, char **argv)
{
	try
	{
		if (argc > 1)
		{
			std::multimap<std::string, float>	csvFile;
			std::multimap<std::string, float>	userFile;

			fillCsvMap(csvFile);
			fillUserMap(userFile, argv);

			BitcoinExchange	test(userFile, csvFile);

			test.printCurrentValue();
			// test.printContainers();
		}
		else
		{
			throw std::runtime_error("Error could not open file");
		}
	}
	catch (std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
