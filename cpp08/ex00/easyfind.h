/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:54:54 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/12 19:15:23 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void	easyfind(const std::vector<T>& intContainer, int find)
{

	for (size_t i = 0; i < intContainer.size(); i++)
	{
		if (intContainer[i] == find)
		{
			std::cout<<"valore trovato nel container"<<std::endl;
			return ;
		}
	}
	throw std::runtime_error("Valore nel container non trovato\n");
}

#endif
