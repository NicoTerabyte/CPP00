/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:16:34 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/18 15:03:05 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    megaphone(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
            std::cout << (char)toupper(av[i][j]);
    }
    std::cout << std::endl;
}

int main(int ac, char **argv)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        megaphone(argv);
    return (0);
}
