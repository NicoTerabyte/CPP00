/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:49:21 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/21 17:50:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "median.hpp"

class ShruberryCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShruberryCreationForm(std::string target = "YoMama");
		// ShruberryCreationForm(std::string target);
		~ShruberryCreationForm();
		std::string getTarget(void) const;
		ShruberryCreationForm(const ShruberryCreationForm& obj);
		ShruberryCreationForm& operator=(const ShruberryCreationForm& obj);

		//AForm method inherited
		virtual void		execute(Bureaucrat const & executor);

};

#endif
