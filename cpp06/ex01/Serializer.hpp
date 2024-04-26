/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:44:45 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/26 14:45:41 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "utils.h"
#include <stdint.h>



class Serializer
{
	private:
		Serializer();
	public:
		~Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(struct Data* ptr);
		//It takes an unsigned integer parameter and converts it to a pointer to Data.
		static struct Data* deserialize(uintptr_t raw);
};




#endif
