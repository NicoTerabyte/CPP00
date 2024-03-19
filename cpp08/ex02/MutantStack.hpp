/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:03:33 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/19 20:20:03 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <algorithm>

/*
per risolvere il dilemma dell'iterazione pare
ci sia bisogno dell'ereditarietà
*/
template <typename T>

class MutantStack
{
	private:
		std::stack<T> noIterate;
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack& operator=(const MutantStack& obj);

		//methods of the class

};


#endif
