/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:16:57 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/22 00:12:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private :

	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap& obj);
		FragTrap& operator=(const FragTrap& obj);
		void highFiveGuys(void);
};

#endif
