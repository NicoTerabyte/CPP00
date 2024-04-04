/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:45:05 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/04 17:09:19 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{

	RPN	expressionStorer;

	try
	{
		if (argc == 2)
		{
			expressionStorer.calculation(argv[1]);
		}
		else
			std::cout<<"Error, you need to put './RPN' and \"expression\" as arguments "<<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
