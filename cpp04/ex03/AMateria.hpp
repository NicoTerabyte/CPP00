/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:32:40 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/17 15:15:46 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria();
		AMateria(AMateria& obj);
		AMateria& operator=(const AMateria& obj);

		std::string const & getType() const; //return materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
