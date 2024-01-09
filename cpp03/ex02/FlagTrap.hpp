/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:16:57 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/09 19:27:33 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
	private :

	public:
		FlagTrap();
		FlagTrap(std::string name);
		~FlagTrap();
		FlagTrap(FlagTrap& obj);
		FlagTrap& operator=(const FlagTrap& obj);
		void highFiveGuys(void);
};

#endif
