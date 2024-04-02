/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:21:20 by lnicoter          #+#    #+#             */
/*   Updated: 2024/04/02 16:51:16 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCAHGE_HPP
#define BITCOINEXCAHGE_HPP

#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <exception>

/*
I'll use the multimap both for the csv database
and for the file database given by the user
even if the csv one has not key duplicates but i don't know
if in the correction is it possible to change the csv file so i won't risk
it

da fare:
	costruttore per inizializzare le mappe bisogna fare in modo che i valori
	dei file vengano letti, suddivisi tra data e valore e salvati nella
	mappa, come farlo è ancora poco chiaro ma troviamo un modo.
	Oppure possiamo utilizzare un approccio un po' più pigro ma effincente dove
	li riempiamo con le stringhe sia per le date che per
*/

class BitcoinExchange
{
	private:
		std::multimap<std::string, float>	userFile;
		std::multimap<std::string, float>	csvFile;

	public:
		BitcoinExchange(std::multimap<std::string, float> userFile, std::multimap<std::string, float> csvFile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange&	operator=(const BitcoinExchange& obj);

		void	printContainers();
		bool	checkerDate(int year, int month, int day);
		void	compareDateToFindValue(std::multimap<std::string, float>::iterator usrIt);
		void	printCurrentValue();

};

#endif
