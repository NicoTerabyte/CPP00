/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:01:06 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/11 16:06:40 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T, typename Func>
void	iter(T *array, int size, Func func)
{
	for (int i = 0; i < size; i++)
		func(array[i]);
}

template <typename T>
void	call(T arrayValue)
{
	std::cout<<"value of the array "<<arrayValue<<std::endl;
}

/*
cioè assurdo, io posso trasformare le funzioni in template
e chiamarle così e se una funzione corrisponde al numero
di argomenti che ho passato e nel main io quando chiamo iter
gli passo come argomento la funzione call così il template si adatta da solo
*/
#endif
