/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:07:22 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/22 16:50:02 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactNumbers = 0;
	this->full = false;
}

int PhoneBook::add()
{
	std::string tmps;

	for (int i = 0; i < 5; i++)
	{
		std::cout <<"Inserisci il " << i + 1<< "° valore\n1)f_name\n2) l_name\n3) nickname\n4) number\n5) secret\n"<<std::endl;
		getline(std::cin, tmps);
		if (tmps.empty())
			return (std::cout << "De' ma che combini porti fuori le vazze?!" << std::endl, 1);
		else if (i == 0)
			this->contacts[contactNumbers].setFName(tmps);
		else if (i == 1)
			this->contacts[contactNumbers].setLName(tmps);
		else if (i == 2)
			this->contacts[contactNumbers].setNickname(tmps);
		else if (i == 3)
			this->contacts[contactNumbers].setPhoneNumber(tmps);
		else if (i == 4)
			this->contacts[contactNumbers].setDarkestSecret(tmps);
	}
	if (this->contactNumbers < 7)
		this->contactNumbers++;
	else
	{
		this->contactNumbers = 0;
		this->full = true;
	}
	return (0);
}

void heading()
{
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"|                CONTATCS LIST              |"<<std::endl;
	std::cout<<"---------------------------------------------"<<std::endl;
}

void print_value(std::string value)
{
	if (value.size() <= 10)
		std::cout<<std::setw(10) << value << "|";
	else
		std::cout<< value.erase(9) << ".|";
}

void PhoneBook::display(int searchIndex)
{
	std::cout<< this->contacts[searchIndex].getFName() << std::endl;
	std::cout<< this->contacts[searchIndex].getLName() << std::endl;
	std::cout<< this->contacts[searchIndex].getNickname() << std::endl;
	std::cout<< this->contacts[searchIndex].getPhoneNumber() << std::endl;
	std::cout<< this->contacts[searchIndex].getDarkestSecret() << std::endl;
}

void PhoneBook::search()
{
	int	numOfContact;
	int	searchIndex;

	if (this->full == true)
		numOfContact = 8;
	else
		numOfContact = this->contactNumbers;
	heading();
	for (int i = 0; i < numOfContact; i++)
	{
		std::cout<<"|";
		std::cout<< std::setw(10);
		std::cout<<i<<"|";
		print_value(this->contacts[i].getFName());
		print_value(this->contacts[i].getLName());
		print_value(this->contacts[i].getNickname());
		std::cout<<std::endl;
	}
	std::cout<<"---------------------------------------------"<<std::endl;
	std::cout<<"Insert the user you want to know about: ";
	std::cin>>searchIndex;
	if (searchIndex > numOfContact)
		std::cout<<"Error wrong index"<<std::endl;
	else
		display(searchIndex);
	std::cin.ignore();
	std::cout<<"\n";
}
