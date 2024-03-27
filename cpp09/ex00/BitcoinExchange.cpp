/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:14:08 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/27 18:29:43 by lnicoter         ###   ########.fr       */
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
