/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MegaPhone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:37:18 by ojacobs           #+#    #+#             */
/*   Updated: 2025/01/28 15:29:32 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

std::string Trim(const std::string& str) 
{
    std::string::size_type start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) 
        ++start;
    std::string::size_type end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) 
        --end;
    return str.substr(start, end - start);
}

void MegaPhone(const std::string& arg)
{
    std::string str = Trim(arg);
    for (std::size_t i = 0; i < str.size(); ++i) {
    std::cout << static_cast<char>(std::toupper(str[i]));
    }
}

int main(int ac, char *av[])
{
    if (ac == 1) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } 
    else 
    {
        for (int i = 1; i < ac; ++i) 
        {
            MegaPhone(av[i]);
            if (i < ac - 1)
                std::cout << " ";  // Add space between words
        }
        std::cout << std::endl;
    }
    return 0;
}
