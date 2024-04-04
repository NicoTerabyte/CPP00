/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:36:28 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/04 17:07:57 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN& obj)
{
	this->expression = obj.expression;
}

RPN&	RPN::operator=(const RPN& obj)
{
	this->expression = obj.expression;

	return *this;
}


void	RPN::calculation(std::string argv)
{
	int	firstN;
	int	secondN;
	std::string::iterator	it;

	for (it = argv.begin(); it != argv.end(); it++)
	{
		if (isdigit(*it))
			this->expression.push(*it - 48);
		else if(*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			secondN = this->expression.top();
			this->expression.pop();
			firstN = this->expression.top();
			this->expression.pop();

			switch (*it)
			{
				case '+':
					this->expression.push(firstN + secondN);
					break;
				case '-':
					this->expression.push(firstN - secondN);
					break;
				case '*':
					this->expression.push(firstN * secondN);
					break;
				case '/':
					this->expression.push(firstN / secondN);
					break;
			}
		}
		else if (!isspace(*it))
			throw std::runtime_error("Error");
	}
	std::cout<<this->expression.top()<<std::endl;
}
