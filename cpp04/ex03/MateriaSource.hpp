/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:53:29 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/12 18:06:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
	private:
		AMateria* known[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);
		
};

#endif
