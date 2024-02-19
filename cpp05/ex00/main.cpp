/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:52 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/19 22:24:45 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat orig("Carlo", 3);
		Bureaucrat primo("Piero", 1);
		Bureaucrat base;
		Bureaucrat evil("spino", 150);
		Bureaucrat roughneck("punto", 150);

		// roughneck.decrementGrade();
		// primo.incrementGrade();
		std::cout<<primo.getGrade()<<std::endl;

		std::cout<<base.getGrade()<<std::endl;
		std::cout<<base.getName()<<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
