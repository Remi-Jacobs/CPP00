/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:05:51 by ojacobs           #+#    #+#             */
/*   Updated: 2025/01/28 14:21:07 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Contact
{
public:
    std::string Fields[5];
};


class Phonebook
{
private:
    Contact MyContacts[8];
public:
    void Add();
    void Search();
    bool isWhitespaceOnly(const std::string& str);
    std::string Trim(const std::string& str);
    std::string toUpper(const std::string &str);
    bool hasWhiteSpaces(const std::string& str);
};

#endif