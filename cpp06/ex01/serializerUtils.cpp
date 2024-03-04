/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializerUtils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:21:55 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/04 19:45:30 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	dataInit(Data& var)
{
	std::cout<<"Data variable init"<<std::endl;
	var.age = 21;
	var.name = "Lorenzo";
	var.lastName = "Nicotera";
	var.married = false;
}

void	dataPrint(Data& var)
{
	std::cout<<"Name: "<<var.name<<std::endl;
	std::cout<<"Last name: "<<var.lastName<<std::endl;
	std::cout<<"Age: "<<var.age<<std::endl;
	std::cout<<"Married: "<<var.married<<std::endl;
}
