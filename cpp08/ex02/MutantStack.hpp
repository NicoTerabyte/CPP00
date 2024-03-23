/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:03:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/22 19:03:35 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>
/*
per risolvere il dilemma dell'iterazione pare
ci sia bisogno dell'ereditarietà
*/
template <typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
	// private:
		// std::stack<T> noIterate;
	public:
		/*mi segno anche le cose che voglio capire meglio per veramente
		sapere che cosa "ho fatto" nell'esercizio*/
		// class Iterator : public std::iterator<std::forward_iterator_tag, T>
		// {
		// 	private:
		// 		typename std::stack<T>::containert_type
		// }

		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack& obj)
		{
			if (this != obj)
				*this = obj;
		}

		MutantStack& operator=(const MutantStack& obj)
		{
			std::stack<T, Container>::operator=(obj);
			return *this;
		}

		typedef typename Container::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}
		//methods of the class

};


#endif
