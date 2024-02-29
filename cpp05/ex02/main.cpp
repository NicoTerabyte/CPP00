/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:52 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/29 15:48:03 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"
#include "PresidetialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	me("Lorenzo", 30);
		PresidentialPardonForm who("damn");
		ShruberryCreationForm plant("home");
		RobotomyRequestForm mech("Cyborg");


		me.signForm(who);
		me.signForm(mech);
		me.signForm(plant);
		me.executeForm(who);
		me.executeForm(mech);
		me.executeForm(plant);
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
