/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:23:57 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/30 02:20:52 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout<<"\nNow we are doing the List version\n"<<std::endl;
	//list version to prove similarity with the mutant stack
	std::list<int>	listVersion;
	listVersion.push_front(5);
	listVersion.push_front(17);
	std::cout<<listVersion.front()<<std::endl;
	listVersion.pop_front();
	std::cout<<listVersion.size()<<std::endl;
	listVersion.push_back(3);
	listVersion.push_back(5);
	listVersion.push_back(737);
	listVersion.push_back(0);

	std::list<int>::iterator	itList = listVersion.begin();
	std::list<int>::iterator	iteList = listVersion.end();

	++itList;
	--itList;
	while (itList != iteList)
	{
		std::cout<< *itList <<std::endl;
		itList++;
	}
	return 0;
}
