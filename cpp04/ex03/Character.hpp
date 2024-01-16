/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:43:10 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/11 21:30:54 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string cName;
		AMateria* inventory[4];
	public:
		Character();
		Character(std::string name);
		~Character();
		Character(Character& obj);
		Character& operator=(const Character& obj);
		/*METHODS inherited*/
		std::string const & getName();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
