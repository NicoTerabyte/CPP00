/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:27:52 by lnicoter          #+#    #+#             */
/*   Updated: 2024/05/02 19:24:46 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidetialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	first("Andromeda",3);
		Bureaucrat	second("Sirio", 10);
		Bureaucrat	third("Phoenix", 15);
		Intern	doItForMe;

		AForm	*randomStuff(doItForMe.makeForm("shruberry request", "alberello"));
		first.signForm(*randomStuff);
		second.executeForm(*randomStuff);
		delete randomStuff;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
