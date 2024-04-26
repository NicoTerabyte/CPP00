/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:23:48 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/26 14:46:10 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::~Serializer()
{}

Serializer::Serializer(const Serializer& obj)
{
	(void)obj;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
	(void) obj;
	return *this;
}

/*
		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(Data* ptr);
		//It takes an unsigned integer parameter and converts it to a pointer to Data.
		static Data* deserialize(uintptr_t raw);
*/
// beta = (uintptr_t)((void*)ptr);

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	beta;

	beta = reinterpret_cast<uintptr_t>((void*)ptr);
	return (beta);
}

	//stuff for testing purposes
	// Data	doll;
	// dataInit(doll);
	// alpha = &doll;

Data* Serializer::deserialize(uintptr_t raw)
{
	Data*	alpha;

	alpha = reinterpret_cast<Data*>(raw);

	return (alpha);
}
