/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:32:36 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/03 15:07:10 by lnicoter         ###   ########.fr       */
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

void	fillUserMap(std::list<std::string> &unorderedDates, std::list<float> &unorderedValues, char **argv)
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
		//damn they are already ordered what can i do?
		if (std::getline(reader, date, '|'))
		{
			if (std::getline(reader, bitCoinValue, '|'))
			{
				std::stringstream	converter(bitCoinValue);
				converter >> coinValue;
				date.erase(date.size() - 1);
				unorderedDates.push_back(date);
				unorderedValues.push_back(coinValue);
			}
			else
			{
				unorderedDates.push_back(date);
				unorderedValues.push_back(0);
			}
		}
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
			// std::multimap<std::string, float>	userFile;
			std::list<std::string>				unorderedDates;
			std::list<float>					unorderedValues;

			fillCsvMap(csvFile);
			fillUserMap(unorderedDates, unorderedValues, argv);

			BitcoinExchange	test(unorderedDates, unorderedValues, csvFile);

			// test.printContainers();
			test.printCurrentValue();
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
