/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:40:08 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/12 17:37:41 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:
		Ice();
		~Ice();
		Ice(Ice& obj);
		Ice& operator=(const Ice& onj);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
