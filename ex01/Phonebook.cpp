/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:37:36 by ojacobs           #+#    #+#             */
/*   Updated: 2025/01/28 16:26:50 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cctype>
#include <csignal>


bool Phonebook::isWhitespaceOnly(const std::string& str) 
{
    for (size_t i = 0; i < str.size(); ++i) {
        if (!std::isspace(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    // If all characters are whitespace, return true
    return true;
}

bool Phonebook::hasWhiteSpaces(const std::string& str) {
    for (std::string::size_type i = 0; i < str.size(); ++i) {
        if (isspace(str[i])) {
            return true;
        }
    }
    return false;
}

std::string Phonebook::Trim(const std::string& str) 
{
    std::string::size_type start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) 
    {
        ++start;
    }
    std::string::size_type end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) 
    {
        --end;
    }
    return str.substr(start, end - start);
}

std::string Phonebook::toUpper(const std::string &str)
{
    std::string upperStr;
    for (size_t i = 0; i < str.length(); i++)
    {
        upperStr += std::toupper(str[i]);
    }
    return upperStr;
}

void Phonebook::Add()
{
    static int i = 0;
    if (i == 8)
        i = 0;

    // Loop to ensure non-empty input for fields 0-3
    for (int field = 0; field < 5; field++) 
    {
        std::string prompt;
        switch (field) 
        {
            case 0: prompt = "Enter First Name: "; break;
            case 1: prompt = "Enter Last Name: "; break;
            case 2: prompt = "Enter Nickname: "; break;
            case 3: prompt = "Enter Phone Number: "; break;
            case 4: prompt = "Enter Darkest Secret: "; break;
        }

        // For fields 0-3, ensure no white spaces
        if (field < 4) {
            // MAKE SURE IT CLEARS TABS IF INSERTED BETWEEN
            do 
            {
                std::cout << prompt;
                std::getline(std::cin, MyContacts[i].Fields[field]);
                 if (std::cin.eof() == true)
                    {
                        return;
                    }
                
                if (MyContacts[i].Fields[field].empty() || hasWhiteSpaces(MyContacts[i].Fields[field])) {
                    std::cout << "Field cannot be empty or contain spaces. Please enter a valid value." << std::endl;
                }
            } 
            while (MyContacts[i].Fields[field].empty() || hasWhiteSpaces(MyContacts[i].Fields[field]));  // Repeat until a non-empty value is entered

            // Additional check for phone number to ensure it's all digits
            if (field == 3) // Assuming field 3 is the phone number
            {
                bool validNumber = true;
                for (std::size_t j = 0; j < MyContacts[i].Fields[3].size(); ++j)
                {
                    if (!isdigit(MyContacts[i].Fields[3][j]))
                    {
                        validNumber = false;
                        break;
                    }
                }
                if (!validNumber) {
                    std::cout << "Phone number must contain only digits. Please enter again." << std::endl;
                    field--;  // Repeat phone number input
                }
            }
        }
        // For field 4 (Darkest Secret), spaces are allowed
        else {
            do {
                std::cout << prompt;
                std::getline(std::cin, MyContacts[i].Fields[field]);
                
                if (MyContacts[i].Fields[field].empty()) {
                    std::cout << "Field cannot be empty. Please enter a valid value." << std::endl;
                }
            } while (MyContacts[i].Fields[field].empty());  // Repeat until a non-empty value is entered
        }
    }
    std::cout << "Contact added successfully!" << std::endl;
    i++;  // Move to the next contact slot
}

void Phonebook::Search() 
{
    if(MyContacts[0].Fields[0].empty())
    {
       std::cout << "Your Phonebook is Empty" << std::endl;
       return;
    }
    int i = 0, j = 0, index = 1;
    std::string info[4];
    std::cout <<"********************************************\n";
    std::cout << "|  index  " << '|' << "First Name" << '|' << "Last Name " <<'|' << " Nickname |" <<'\n';
    std::cout <<"********************************************\n";
    while(i < 8 && !MyContacts[i].Fields[j].empty())
    {
        for (int j = 0; j < 3; j++) 
        {
            if (MyContacts[i].Fields[j].size() > 10) {
                info[j] = MyContacts[i].Fields[j].substr(0, 9) + '.';
            } else {
                info[j] = MyContacts[i].Fields[j];
            }
        }
        std::cout << std::setw(10) << index++ << '|' << std::setw(10) << info[0] << '|' 
                  << std::setw(10) << info[1] << '|' 
                  << std::setw(10) << info[2] << std::endl;
        i++;
    }
    
    int contact_index;
    do
    {
        std::cout << "Please enter the number of the contact you want to view ";
        std::cin >> contact_index;
        if (std::cin.eof() == true)
        {
            return;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (contact_index < 1 || contact_index > i)
            std::cout << "You entered and invalid contact number, Please enter and number between 1 and  " << (i) << std::endl;
    } while (contact_index < 1 || contact_index > i);
    int selected = contact_index - 1;
    std::cout << "First Name: " << MyContacts[selected].Fields[0] << std::endl;
    std::cout << "Last Name: "<< MyContacts[selected].Fields[1] << std::endl;
    std::cout << "Nickname: "<< MyContacts[selected].Fields[2] << std::endl;
    std::cout << "Phone Number: "<< MyContacts[selected].Fields[3] << std::endl;
    std::cout << "Darkest Secret: "<< MyContacts[selected].Fields[4] << std::endl;
    return;
}

void quit_signals(int signal)
{
    (void)signal;
    std::cout << "quit signal CTRL + \\ detected" << std::endl;
    _exit(1);
}

int main()
{
    signal(SIGQUIT, quit_signals);
    Phonebook NewPhoneBook;
    std::string input;
    int i = 0;
    std::cout << "***************************************************************" << '\n';
    std::cout << "Welcome to your Phone Book. Select an option: ADD, SEARCH, EXIT" << '\n';
    std::cout << "***************************************************************" << '\n';
    do
    {
        std::getline(std::cin, input);
        if (std::cin.eof() == true)
        {
            return(1);
        }
        // Reset input stream errors
        std::cin.clear();

        // Convert the input to uppercase for case-insensitive comparison
        input = NewPhoneBook.Trim(input);
        input = NewPhoneBook.toUpper(input);
        
        if (input == "ADD")
            i = 1;
        else if (input == "SEARCH")
            i = 2;
        else if (input == "EXIT")
            i = 3;
        else
            i = 4;

        switch (i)
        {
        case 1:
            NewPhoneBook.Add();
            std::cout << "Select an option: ADD, SEARCH, EXIT" << '\n';
            break;
        case 2:
            NewPhoneBook.Search();
            std::cout << "Select an option: ADD, SEARCH, EXIT" << '\n';
            break;
        case 3:
            std::cout << "Goodbye!" << '\n';
            break;
        default:
            std::cout << "Invalid command! Please enter a one of the following:\n1)ADD\n2)SEARCH\n3)EXIT" << '\n';
        }

    } while (i != 3);

    return 0;
}