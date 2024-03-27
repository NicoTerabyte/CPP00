/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:32:36 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/27 18:29:29 by lnicoter         ###   ########.fr       */
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
		std::cerr<<"Impossibile aprire il file "<<std::endl;
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
			std::cout<<"valore contenuto in bitcoin value "<<bitCoinValue<<std::endl;
			converter >> coinValue;
			csvFile.insert(std::make_pair(date, coinValue));
		}
	}
	file.close();
	for (std::multimap<std::string,float>::iterator	it = csvFile.begin();
			it != csvFile.end(); ++it)
	{
		std::cout<<"Valore mappa "<<it->first<<" | "<<it->second<<std::endl;
	}
}

void	fillUserMap(std::multimap<std::string, float> &userFile)
{
	std::ifstream		file("data.csv");
	std::string			line;
	std::stringstream	reader;

	float	coinValue;
	file.open("testFile.txt");
	std::getline(file, line);
	if (!file.is_open())
	{
		std::cerr<<"Impossibile aprire il file "<<std::endl;
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
			userFile.insert(std::make_pair(date, coinValue));
		}
	}
	file.close();
	for (std::multimap<std::string,float>::iterator	it = userFile.begin();
		it != userFile.end(); ++it)
	{
		std::cout<<"Valore mappa "<<it->first<<" | "<<it->second<<std::endl;
	}
}

int	main(void)
{

	std::multimap<std::string, float>	csvFile;
	std::multimap<std::string, float>	userFile;

	fillCsvMap(csvFile);
	fillUserMap(userFile);

	BitcoinExchange	test(userFile, csvFile);

	test.printContainers();
	return (0);
}
