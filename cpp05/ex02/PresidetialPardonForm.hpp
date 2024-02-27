/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidetialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:01:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 20:27:51 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class AForm;

class PresidentialPardonForm : virtual public AForm
{
	private:
		std::string target;
		const int	sign;
		const int	exec;

	public:
		PresidentialPardonForm(std::string target = "yoMama");
		~PresidentialPardonForm();
		std::string getTarget(void) const;
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

		//methods inherited
		void execute(Bureaucrat const & executor) const;
};

#endif
