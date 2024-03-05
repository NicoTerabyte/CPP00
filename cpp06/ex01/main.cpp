/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:55:41 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/05 17:04:11 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(void)
{
	Data	base;
	Data	*pBase;
	Data	*cecker;

	uintptr_t	serial;

	dataInit(base);
	// dataPrint(base);

	pBase = &base;
	dataPrint(*pBase);
	serial = Serializer::serialize(pBase);

	cecker = Serializer::deserialize(serial);
	dataPrint(*pBase);
	dataPrint(*cecker);

	std::cout<<"Check of the address:\n"<<pBase<<" the copy "<<cecker<<std::endl;
	if (pBase == cecker)
		std::cout<<"all ok"<<std::endl;
	return (0);
}
