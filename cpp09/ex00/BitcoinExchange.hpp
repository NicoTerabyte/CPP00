/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:21:20 by lnicoter          #+#    #+#             */
/*   Updated: 2024/03/25 17:23:20 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCAHGE_HPP
#define BITCOINEXCAHGE_HPP

#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include <iomanip>


/*
I'll use the multimap both for the csv database
and for the file database given by the user
even if the csv one has not key duplicates but i don't know
if in the correction is it possible to change the csv file so i won't risk
it

da fare:
	costruttore per inizializzare le mappe bisogna fare in modo che i valori
	dei file vengano letti, suddivisi tra data e valore e salvati nella
	mappa, come farlo è ancora poco chiaro ma troviamo un modo
*/

class BitcointExchange
{
	private:
		std::multimap<std::string, int>	userFile;
		std::multimap<std::string, int>	csvFile;
		std::string						strRead; //la stringa intera prima di essere separata
		std::string						dateAndValue[2]; // la stringa suddivisa avendo data e valore
	public:


};

#endif
