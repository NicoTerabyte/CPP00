/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:34 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/06 19:27:10 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

		// Fixed(int fixedPointVal = 0);
		// ~Fixed();
		// Fixed(Fixed &obj);
		// Fixed& operator=(const Fixed &obj);
		// int getFixedPointVal(void);
		// void setFixexPointVal(int fixedPointVal);

Fixed::Fixed():fixedVal(0)
{
	std::cout <<"Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called\n";
}

Fixed::Fixed(Fixed &obj)
{
	std::cout<<"Copy constructor called\n";
	this->fixedVal = obj.fixedVal;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout <<"Copy assignement operator called\n";
	if (this != &obj)
		(this->fixedVal) = (obj.fixedVal);
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"Function getRawBits called\n";
	return this->fixedVal;
}

void Fixed::setRawBits(int fixedVal)
{
	std::cout<<"Function setRawBits called\n";
	this->fixedVal = fixedVal;
}

