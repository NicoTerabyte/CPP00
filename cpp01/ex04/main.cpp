/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:47:46 by lnicoter          #+#    #+#             */
/*   Updated: 2024/01/18 13:54:59 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.hpp"

/*
fstream è una libreria presente nella libreria standard di
c++ che serve per leggere e manipolare i file

ifstream si utilizza per prendere il file in fase di lettura
ofstream al contrario si usa per scrivere su un file
*/

void changeString(std::string &line, std::string s1, std::string s2)
{
	size_t	found = line.find(s1);

	while (found != std::string::npos)
	{
		line = line.substr(0, found) + s2 + line.substr(found + s1.length());
		found = line.find(s1, found + s2.length());
	}
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::ifstream theFile(av[1]);
		if (theFile.is_open())
		{
			std::string line;
			std::string &aliasLine = line;
			std::string newFileName = av[1];

			newFileName.append(".replace");
			std::ofstream replaceFile(newFileName.c_str());

			while (std::getline(theFile, line))
			{
				changeString(aliasLine, av[2], av[3]);
				replaceFile << line <<"\n";
			}
		}
		else
			std::cout << "Error wrong file is not possible to open it\n";
	}
	else
		std::cout<<"Not enough arguments\n";
	return (0);
}
