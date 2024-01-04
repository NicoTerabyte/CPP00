/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:56:35 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/29 20:08:14 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string brian = "HI THIS IS BRAIN";
	std::string* strignPTR = &brian;
	std::string& stringREF = brian;

	std::cout << &brian << std::endl;
	std::cout << &strignPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << brian << std::endl;
	std::cout << *strignPTR << std::endl;
	std::cout << stringREF << std::endl;

}
