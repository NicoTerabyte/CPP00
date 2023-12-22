/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:48:17 by lnicoter          #+#    #+#             */
/*   Updated: 2023/12/20 16:54:57 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
	std::string fName;
	std::string lName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	std::string getFName();
	std::string getLName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
	void		setFName(std::string tmp);
	void		setLName(std::string tmp);
	void		setNickname(std::string tmp);
	void		setPhoneNumber(std::string tmp);
	void		setDarkestSecret(std::string tmp);
};



#endif
