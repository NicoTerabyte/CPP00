/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:33:25 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/03 20:31:41 by lnicoter         ###   ########.fr       */
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
	bool	overflow = false;

	if (halfLiteralsCheck(value))
		printHalfLiteral(value);
	else //impotetico check caratteri normali
	{
		overflow = checkUnderOverflow(value);
		std::stringstream converter(value);
		converter >> ScalarConverter::conDouble;
		ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
		ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
		ScalarConverter::conChar = static_cast<char>(ScalarConverter::conInt);
		printConv(overflow);
	}
}
