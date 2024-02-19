/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:52 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/19 16:12:50 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat orig("Carlo", 3);
		Bureaucrat primo("Piero", 1);

		Bureaucrat evil("spino", 150);
		Bureaucrat roughneck("punto", 150);

		roughneck.decrementGrade();
		primo.incrementGrade();
		std::cout<<primo.getGrade()<<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
