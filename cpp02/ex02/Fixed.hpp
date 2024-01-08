/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:41 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/08 12:31:51 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedVal;
		static const int fractBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		int getRawBits(void) const;
		void setRawBits(int fixedVal);
		/*ex01*/
		Fixed(const int fixedVal);
		Fixed(const float fixedVal);
		float toFloat(void) const;
		int toInt(void) const;
		/*ex02*/
		bool operator<(const Fixed& obj);
		bool operator>(const Fixed& obj);
		bool operator<=(const Fixed& obj);
		bool operator>=(const Fixed& obj);
		bool operator==(const Fixed& obj);
		bool operator!=(const Fixed& obj);
		Fixed operator+(const Fixed& obj);
		Fixed operator-(const Fixed& obj);
		Fixed operator*(const Fixed& obj);
		Fixed operator/(const Fixed& obj);
		static Fixed& min(Fixed& objA, Fixed& objB);
		static const Fixed& min(const Fixed& objA, const Fixed& objB);
		static Fixed& max(Fixed& objA, Fixed& objB);
		static const Fixed& max(const Fixed& objA, const Fixed& objB);
		Fixed& operator++(); //incremento prefisso deifinto dal ritorno della referenza
		Fixed& operator--();
		Fixed operator++(int); //incremnto postfisso definito da int
		Fixed operator--(int);
};
/*ex01*/
std::ostream& operator<<(std::ostream& os, const Fixed& obj);
/*ex02*/


#endif

/*
26.5

2^4*1, 2^3 * 1, 2^2 *0, 2^1 * 0, 2^0 * 1,point,  2^-1 * 1
16,     8,      0,     2,       0,  .            1


Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
*/
