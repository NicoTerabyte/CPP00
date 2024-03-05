/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:23:48 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/05 16:57:48 by lnicoter         ###   ########.fr       */
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

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	beta;

	beta = (uintptr_t)((void*)ptr);
	// beta = reinterpret_cast<uintptr_t>((void*)ptr);
	return (beta);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	// Data	fantoccio;
	Data*	alpha;

	// dataInit(fantoccio);
	// alpha = &fantoccio;
	alpha = (Data*)raw;

	return (alpha);
}
