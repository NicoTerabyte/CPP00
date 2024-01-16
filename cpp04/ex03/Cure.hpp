/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:40:05 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/12 17:40:37 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		~Cure();
		Cure(Cure& obj);
		Cure& operator=(const Cure& onj);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
