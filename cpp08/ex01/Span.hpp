
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:02:39 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/18 18:28:23 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	array;
		Span();
	public:
		//orthodox form
		Span(unsigned int n);
		~Span();
		Span(const Span& obj);
		Span&	operator=(const Span& obj);

		//methods i need to implement
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();

		//extra method to add more numbers in one go
		void	allInOne();

		//printing for help
		void	printCont();
};

#endif
