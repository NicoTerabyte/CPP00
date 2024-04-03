/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:14:08 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/03 15:52:38 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::list<std::string> date, std::list<float> btCoinValue, std::multimap<std::string, float> csvFile)
{
	std::cout<<"Default constructor called"<<std::endl;
	this->date = date;
	this->btCoinValue = btCoinValue;
	this->csvFile = csvFile;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout<<"Destructor called"<<std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) : date(obj.date), btCoinValue(obj.btCoinValue), csvFile(obj.csvFile)
{
	std::cout<<"Copy constructor called"<<std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	std::cout<<"Operator overloading called"<<std::endl;
	this->date = obj.date;
	this->btCoinValue = obj.btCoinValue;
	this->csvFile = obj.csvFile;

	return *this;
}

void	BitcoinExchange::printContainers()
{
	std::list<std::string>::iterator it;

	for (it = this->date.begin(); it != this->date.end(); ++it)
	{
		std::cout<<"it value "<<*it<<std::endl;
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

void	BitcoinExchange::compareDateToFindValue(std::list<std::string>::iterator usrIt,
	std::list<float>::iterator usrItValue, int year, int month, int day)
{
	std::multimap<std::string, float>::iterator csvIt;
	std::multimap<std::string, float>::iterator	finder = this->csvFile.find(*usrIt);
	if (checkerDate(year, month, day))
	{
		if (finder != this->csvFile.end())
		{
			std::cout<<*usrIt<<" => "<<*usrItValue<<" = "<<finder->second * *usrItValue<<std::endl;
		}
		else
		{
			finder = this->csvFile.lower_bound(*usrIt);
			--finder;
			if (finder != this->csvFile.begin())
			{
				std::cout<<*usrIt<<" => "<<*usrItValue<<" = "<<finder->second * *usrItValue<<std::endl;
			}
			else
			{
				std::cout<<"no data found"<<std::endl;
			}
		}
	}
	else
		std::cout<<"Error bad input => "<<*usrIt<<std::endl;
}

void	BitcoinExchange::printCurrentValue()
{
	std::list<std::string>::iterator			it;
	std::list<float>::iterator					itVal = this->btCoinValue.begin();
	std::stringstream							ss;
	char										sep;
	int											year, month, day;


	// printContainers();
	for (it = this->date.begin(); it != this->date.end(); ++it)
	{
		ss.clear();
		ss.str(*it);
		ss >> year >> sep >> month >> sep >> day;
		// std::cout<<"it honest reaction: "<<*it<<std::endl;
		// if (checkerDate(year, month, day))
		if (*itVal >= 0 && *itVal <= 1000)
		{
			//here we will call the function to
			//Calculate how much the bitcoin values
			//like we do a comparison of the dates to know the value of the bt
			compareDateToFindValue(it, itVal, year, month, day);
		}
		else
		{
			if (*itVal >= 1000)
				std::cout<<"Error: too large number"<<std::endl;
			else
				std::cout<<"Error: not a positive number"<<std::endl;
		}
		// else
		// 	std::cout<<"Error bad input "<<it->first<<std::endl;
		++itVal;
	}
}
