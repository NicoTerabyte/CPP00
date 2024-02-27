/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:44:41 by lnicoter          #+#    #+#             */
/*   Updated: 2024/02/27 20:37:04 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "median.hpp"

class RobotomyRequestForm :  virtual public AForm
{
	private:
		std::string target;
		const int	sign;
		const int	exec;
	public:
		RobotomyRequestForm(std::string target = "YoMama");
		~RobotomyRequestForm();
		std::string getTarget(void) const;
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

		//AForm method inherited
		void		execute(Bureaucrat const & executor) const;
};

#endif
