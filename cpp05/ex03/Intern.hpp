/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:43:43 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/26 22:09:01 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "median.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidetialPardonForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);

		AForm*	makeForm(std::string formType, std::string formName);

};

#endif
