/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidetialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:01:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/29 15:38:15 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "median.hpp"
class AForm;

class PresidentialPardonForm : virtual public AForm
{
	private:
		const std::string target;

	public:
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		std::string getTarget(void) const;
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

		//methods inherited
		void execute(const Bureaucrat& executor) const;
};

#endif
