/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:14:08 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/02 17:04:36 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::multimap<std::string, float> userFile, std::multimap<std::string, float> csvFile)
{
	std::cout<<"Default constructor called"<<std::endl;
	this->userFile = userFile;
	this->csvFile = csvFile;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout<<"Destructor called"<<std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) : userFile(obj.userFile), csvFile(obj.csvFile)
{
	std::cout<<"Copy constructor called"<<std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	std::cout<<"Operator overloading called"<<std::endl;
	this->userFile = obj.userFile;
	this->csvFile = obj.csvFile;

	return *this;
}

void	BitcoinExchange::printContainers()
{
	std::multimap<std::string, float>::iterator	usIt;
	std::multimap<std::string, float>::iterator	csvIt ;

	std::cout<<"User file values"<<std::endl;
	for (usIt = this->userFile.begin(); usIt != this->userFile.end(); ++usIt)
	{
		std::cout<<usIt->first<<" | "<<usIt->second<<std::endl;
	}

	std::cout<<"Csv file values"<<std::endl;
	for (csvIt = this->csvFile.begin(); csvIt != this->csvFile.end(); ++csvIt)
	{
		std::cout<<csvIt->first<<" , "<<csvIt->second<<std::endl;
	}
}

/*
Come implementerò le cose adesso:
	1. Checker molto banale della data per comprendere
		se è valida o no
	2. Controllo dei numeri che siano positivi o 0
	3. Faccio un tentativo per calcolare il valore dei bitcoin
		in base al file csv
	3.5 2 e 3 possono essere fatte insieme
	4. Ricerca della data più vicina corrispondente ad una che
		non è presente nel file csv
*/

bool	BitcoinExchange::checkerDate(int year, int month, int day)
{
	std::cout<<"Here we are checking the dates "<<year<<" "<<month<<" "<<day<<std::endl;
	if (year < 2009)
		return	false;
	if (month < 1 || month > 12)
		return	false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
			return false;
	}
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day < 1 || day > 29)
				return false;
		}
		else if (day < 1 || day > 28)
			return false;
	}
	return true;
}

/*
	Questo è il piano:
		Abbiamo sto iteratore che praticamente
		ha al suo iterno la data attuale del file
		datoci e la quantità di btc che dobbiamo moltiplicare
		per il valore di quelli in "data csv"
		questo che vor dì, vor dì che adesso dobbiamo
		trovare la data uguale a quella dell'iteratore e moltiplicare
		il numero di btc per il valore
*/

void	BitcoinExchange::compareDateToFindValue(std::multimap<std::string, float>::iterator usrIt)
{
	std::multimap<std::string, float>::iterator	found  = this->csvFile.find(usrIt->first);

	if (found == this->csvFile.end())
	{
		std::multimap<std::string, float>::iterator it = this->csvFile.lower_bound(usrIt->first);
		if (it != this->csvFile.begin())
		{
			it--;
			std::cout<<"Closest smaller data found "<<it->first<<std::endl;
			std::cout<<"test calculation: "<<it->second * usrIt->second<<std::endl;
		}
		else
			std::cout<<"No previous data found"<<std::endl;
	}
	else
	{
		std::cout<<"test calculation: "<<found->second * usrIt->second<<std::endl;
	}
}

void	BitcoinExchange::printCurrentValue()
{
	std::multimap<std::string, float>::iterator	it;
	std::stringstream							ss;
	char										sep;
	int											year, month, day;

	for (it = this->userFile.begin(); it != this->userFile.end(); ++it)
	{
		ss.clear();
		ss.str(it->first);
		ss >> year >> sep >> month >> sep >> day;
		// std::cout<<"it honest reaction: "<<it->first<<std::endl;
		if (checkerDate(year, month, day))
		{
			if (it->second >= 0 && it->second <= 1000)
			{
				//here we will call the function to
				//Calculate how much the bitcoin values
				//like we do a comparison of the dates to know the value of the bt
				compareDateToFindValue(it);
			}
			else
			{
				std::cout<<"Only positive numbers and they must be less or equal to 1000"<<std::endl;
			}

		}
		else
			std::cout<<"Not a valid date"<<std::endl;
	}
}
