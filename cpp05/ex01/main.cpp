/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:52 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/20 15:51:17 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "median.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	firstDay("Davide", 11);
		Form		firstForm("Possibility to drive", 10, 2);

		// firstForm.beSigned(firstDay);
		std::cout<<firstForm<<std::endl;
		firstDay.signForm(firstForm);
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
