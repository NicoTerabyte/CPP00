/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:33:25 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/23 17:23:46 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// ScalarConverter::ScalarConverter()
// {}
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
	else //ipotetico check caratteri normali
	{
		std::stringstream test(value);
		test >> ScalarConverter::conInt;
		if (printChar != 0)
		{
			std::stringstream converter(value);
			converter >> ScalarConverter::conChar;
			std::cout<<ScalarConverter::conChar<<std::endl;
			if (ScalarConverter::conChar >= '0' || ScalarConverter::conChar <= '9')
			{
				ScalarConverter::conDouble = static_cast<double>((ScalarConverter::conChar - 48));
				ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
				ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
			}
			else
			{
				ScalarConverter::conDouble = static_cast<double>((ScalarConverter::conChar ));
				ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
				ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
			}
		}
		else
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
}
