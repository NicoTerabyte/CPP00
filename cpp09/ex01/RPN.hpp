/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:45:20 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/03 23:48:42 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <iterator>
#include <exception>

class RPN
{
	private:
		std::stack<int>	expression;

	public:
		RPN();
		~RPN();
		RPN(const RPN& obj);
		RPN& operator=(const RPN& obj);
		
};

#endif
