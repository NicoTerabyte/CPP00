/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:44:41 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/29 15:38:42 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "median.hpp"

class RobotomyRequestForm :  virtual public AForm
{
	private:
		const std::string target;

	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		std::string getTarget(void) const;
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

		//AForm method inherited
		void		execute( const Bureaucrat& executor) const;
};

#endif
