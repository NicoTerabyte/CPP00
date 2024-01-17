/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:02:46 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/17 15:21:08 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);

		void learnMateria(AMateria* theMateria);
		AMateria* createMateria(std::string const & type);
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->known[i] = NULL;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource::MateriaSource(MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
		this->known[i] = obj.known[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
		this->known[i] = obj.known[i];
	return *this;
}

void MateriaSource::learnMateria(AMateria* theMateria)
{
	/*devo controllare come character che il massimo non sia stato raggiunto eh*/
	for (int i = 0; i < 4; i++)
	{
		if (this->known[i] == NULL)
		{
			this->known[i] = theMateria;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (known[i] && known[i]->getType() == type)
			return known[i]->clone();
	}
	return NULL;
}
