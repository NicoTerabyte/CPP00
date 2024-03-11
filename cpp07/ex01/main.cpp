/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:26 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/11 17:16:30 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

int	main(void)
{
	int	size = 20;
	int	chunck[size];
	std::string	base = "generic";
	for (int i = 0; i < size; i++)
		chunck[i] = i + 1;
	//per le funzioni devi per forza specificare
	//visto che sono puntatori a funzione non hanno un tipo definito
	//essendo puntatori di conseguenza il compilatore non sa dedurli
	iter(chunck, size, call<int>);

	//example with strings
	std::string	sChunck[size];
	sChunck[0] = "tu madre";
	for (int i = 1; i < size; i++)
		sChunck[i] = sChunck[i - 1] + base;
	iter(sChunck, size, call<std::string>);
}
