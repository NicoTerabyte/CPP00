/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:22:03 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/20 17:06:08 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	;
}



std::string Contact::getFName()
{
	return this->fName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getLName()
{
	return this->lName;
}

std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}

void		Contact::setFName(std::string tmp)
{
	this->fName = tmp;
}
void		Contact::setLName(std::string tmp)
{
	this->lName = tmp;
}
void		Contact::setNickname(std::string tmp)
{
	this->nickname = tmp;
}
void		Contact::setPhoneNumber(std::string tmp)
{
	this->phoneNumber = tmp;
}
void		Contact::setDarkestSecret(std::string tmp)
{
	this->darkestSecret = tmp;
}
