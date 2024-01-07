/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:30:41 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/06 19:19:07 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedVal;
		static const int fractBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		int getRawBits(void) const;
		void setRawBits(int fixedVal);
};

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
