/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:21:11 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/04 12:03:31 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "ScalarConverter.hpp"

void	printConv(int doNotPrintChar, int printChar, char cArgv);
int		halfLiteralsCheck(std::string argv);
void	printHalfLiteral(std::string value);
int		checkUnderOverflow(std::string value);

#endif
