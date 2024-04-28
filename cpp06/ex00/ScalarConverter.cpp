/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:33:25 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/28 19:03:58 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	ScalarConverter::conChar;
int		ScalarConverter::conInt;
float	ScalarConverter::conFloat;
double	ScalarConverter::conDouble;


ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return *this;
}

void	ScalarConverter::convert(std::string value)
{
	int	overflow = 0;
	int	printChar = 0;

	if ((printChar = halfLiteralsCheck(value)) && (halfLiteralsCheck(value) == 1))
		printHalfLiteral(value);
	if (printChar != 0)
	{
		std::stringstream converter(value);
		converter >> ScalarConverter::conChar;
		if (ScalarConverter::conChar >= '0' && ScalarConverter::conChar <= '9')
		{
			ScalarConverter::conDouble = static_cast<double>(ScalarConverter::conChar - 48);
			ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
			ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
		}
		else
		{
			ScalarConverter::conDouble = static_cast<double>(ScalarConverter::conChar);
			ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
			ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
		}
	}
	else //ipotetico check caratteri normali
	{
		overflow = checkUnderOverflow(value);
		std::stringstream converter(value);
		converter >> ScalarConverter::conDouble;
		ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
		ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
		ScalarConverter::conChar = static_cast<char>(ScalarConverter::conInt);
	}
	printConv(overflow, printChar, value[0]);
}
