/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:34 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/07 19:02:09 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

		// Fixed(int fixedPointVal = 0);
		// ~Fixed();
		// Fixed(Fixed &obj);
		// Fixed& operator=(const Fixed &obj);
		// int getFixedPointVal(void);
		// void setFixexPointVal(int fixedPointVal);
		/*ex01*/
		// Fixed(const int fixedVal);
		// Fixed(const float fixedVal);
		// float toFloat(void) const;
		// int toInt(void) const;

Fixed::Fixed():fixedVal(0)
{
	std::cout <<"Default constructor called\n";
}

Fixed::Fixed (const int fixedVal)
{
	std::cout <<"Int constructor called\n";
	this->fixedVal = fixedVal << fractBits;
}

Fixed::Fixed(const float fixedVal)
{
	std::cout << "Float constructor called\n";
	this->fixedVal = roundf(fixedVal * (1 << fractBits));
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called\n";
}

Fixed::Fixed(const Fixed &obj)
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

float Fixed::toFloat(void) const
{
	return float(this->fixedVal) / (1 << this->fractBits);
}

int Fixed::toInt(void) const
{
	return this->fixedVal >> this->fractBits;
}

//non va bene bisogna sistemare le conversioni prima
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
