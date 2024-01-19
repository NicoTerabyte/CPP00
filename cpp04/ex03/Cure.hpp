/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:40:05 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/19 14:49:25 by lnicoter         ###   ########.fr       */
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
		virtual ~Cure();
		Cure(const Cure& obj);
		Cure& operator=(const Cure& onj);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
