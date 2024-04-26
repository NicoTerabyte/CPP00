/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:21:11 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/26 14:44:34 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "Serializer.hpp"


struct Data
{
	std::string	name;
	std::string	lastName;
	int			age;
	bool		married;
};

void	dataInit(struct Data& var);
void	dataPrint(struct Data& var);
#endif
