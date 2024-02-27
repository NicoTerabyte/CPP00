/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:52 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 20:46:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ShruberryCreationForm.hpp"
#include "PresidetialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	me("Lorenzo", 1);
		PresidentialPardonForm who("damn");

		who.beSigned(me);
		who.execute(me);
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
