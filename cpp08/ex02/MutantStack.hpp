/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:03:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/23 21:36:49 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>
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
	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack& obj)
		{
			if (*this != obj)
				*this = std::stack<T, Container>::operator=(obj);
		}

		MutantStack& operator=(const MutantStack& obj)
		{
			if (*this != obj)
				this->c = obj.c;
			return *this;
		}
		// i define the name of my iterators with typedef so i make
		//the iterators for the class
		// i use typename too because container is a template
		typedef typename Container::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}

};


/*
How should implement the iterator function outside of the class field:

template<typename T, typename container_type>
typename MutantStack<T, container_type>::iterator	MutantStack<T, container_type>::begin()
{
	return (this->c.begin());
};

template<typename T, typename container_type>
typename MutantStack<T, container_type>::iterator	MutantStack<T, container_type>::end()
{
	return (this->c.end());
};
*/
#endif
