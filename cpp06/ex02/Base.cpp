/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:17:25 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/29 15:49:40 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


Base::~Base()
{

}

A::A()
{
	std::cout<<"A constructor called"<<std::endl;
}

A::~A()
{
	std::cout<<"A destructor called"<<std::endl;
}

B::B()
{
	std::cout<<"B constructor called"<<std::endl;
}

B::~B()
{
	std::cout<<"B destructor called"<<std::endl;
}


C::C()
{
	std::cout<<"C constructor called"<<std::endl;
}

C::~C()
{
	std::cout<<"C destructor called"<<std::endl;
}

Base * generate(void)
{
	int		picker;
	Base	*guessWho;

	srand((time(NULL)));

	picker = (rand() % 3) + 1;
	if (picker == 1)
		guessWho = new A();
	else if (picker == 2)
		guessWho = new B();
	else
		guessWho = new C();

	return (guessWho);
}

// delete checker1;
// delete checker2;

void identify(Base* p)
{
	A*	checker1;
	B*	checker2;

	if ((checker1 = dynamic_cast<A*>(p)))
		std::cout<<"Type A"<<std::endl;
	else if ((checker2 = dynamic_cast<B*>(p)))
		std::cout<<"Type B"<<std::endl;
	else
		std::cout<<"Type C"<<std::endl;

}

void identify(Base& p)
{
	try
	{
		A& checker1 = dynamic_cast<A&>(p);
		std::cout<<"Type A"<<std::endl;
		(void)checker1;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& checker2 = dynamic_cast<B&>(p);
			std::cout<<"Type B"<<std::endl;
			(void)checker2;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& checker3 = dynamic_cast<C&>(p);
				std::cout<<"Type C"<<std::endl;
				(void)checker3;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

	}
}

/* i need to remember what the dynamic cast does*/
