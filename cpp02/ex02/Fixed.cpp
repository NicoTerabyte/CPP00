/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:46:34 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/08 12:30:58 by lnicoter         ###   ########.fr       */
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
{}

Fixed::Fixed (const int fixedVal)
{
	this->fixedVal = fixedVal << fractBits;
}

Fixed::Fixed(const float fixedVal)
{
	this->fixedVal = roundf(fixedVal * (1 << fractBits));
}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed &obj)
{
	this->fixedVal = obj.fixedVal;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
		(this->fixedVal) = (obj.fixedVal);
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->fixedVal;
}

void Fixed::setRawBits(int fixedVal)
{
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

		// static int& min(Fixed& objA, Fixed& objB);
		// static const int& min(const Fixed& objA, const Fixed& objB);
		// static int& max(Fixed& objA, Fixed& objB);
		// static const int& max(const Fixed& objA, const Fixed& objB);

bool Fixed::operator<(const Fixed& obj)
{
	return this->fixedVal < obj.fixedVal;
}

bool Fixed::operator>(const Fixed& obj)
{
	return this->fixedVal > obj.fixedVal;
}

bool Fixed::operator<=(const Fixed& obj)
{
	return this->fixedVal <= obj.fixedVal;
}

bool Fixed::operator>=(const Fixed& obj)
{
	return this->fixedVal >= obj.fixedVal;
}

bool Fixed::operator==(const Fixed& obj)
{
	return this->fixedVal == obj.fixedVal;
}

bool Fixed::operator!=(const Fixed& obj)
{
	return this->fixedVal != obj.fixedVal;
}

Fixed Fixed::operator+(const Fixed& obj)
{
	Fixed tmp = this->toFloat() + obj.toFloat();
	return tmp;
}

Fixed Fixed::operator-(const Fixed& obj)
{
	Fixed tmp = this->toFloat() - obj.toFloat();
	return tmp;
}

Fixed Fixed::operator*(const Fixed& obj)
{
	Fixed tmp = (this->toFloat() * obj.toFloat());
	return tmp;
}

Fixed Fixed::operator/(const Fixed& obj)
{
	Fixed tmp = this->toFloat() / obj.toFloat();
	return tmp;
}

Fixed& Fixed::min(Fixed& objA, Fixed& objB)
{
	if (objA.fixedVal < objB.fixedVal)
		return objA;
	else if (objA.fixedVal > objB.fixedVal)
		return objB;
	return objA;
}

const Fixed& Fixed::min(const Fixed& objA, const Fixed& objB)
{
	if (objA.fixedVal < objB.fixedVal)
		return objA;
	else if (objA.fixedVal > objB.fixedVal)
		return objB;
	return objA;
}


Fixed& Fixed::max(Fixed& objA, Fixed& objB)
{
	if (objA.fixedVal < objB.fixedVal)
		return objB;
	else if (objA.fixedVal > objB.fixedVal)
		return objA;
	return objA;
}

const Fixed& Fixed::max(const Fixed& objA, const Fixed& objB)
{
	if (objA.fixedVal < objB.fixedVal)
		return objB;
	else if (objA.fixedVal > objB.fixedVal)
		return objA;
	return objA;
}

Fixed& Fixed::operator++()
{
	this->fixedVal++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->fixedVal--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	this->fixedVal++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->fixedVal--;
	return tmp;
}
