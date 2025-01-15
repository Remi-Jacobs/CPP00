#include <iostream>
#include <string>
#include <cctype>

//char *Trim(const char *str)
std::string Trim(const std::string& str) 
{
    // Find the position of the first non-whitespace character
    std::string::size_type start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) 
    {
        ++start;
    }

    // Find the position of the last non-whitespace character
    std::string::size_type end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) 
    {
        --end;
    }

    // Return the trimmed substring
    return str.substr(start, end - start);
}
//char *ToUpperCase (const char *str)
std::string ToUpperCase(const std::string& str) 
{
    std::string result = str; // Create a copy of the string to modify
    for (std::size_t i = 0; i < result.size(); ++i) 
    {
        result[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(result[i])));
    }
    return result;
}
//void MegaPhone (const char *str)
void MegaPhone(const std::string& str)
{
   std::string result = Trim(str);
   result = ToUpperCase(result);
   std::cout << result; 
}

int main(int ac, char *av[])
{
    if (ac == 1) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    } 
    else 
    {
        for (int i = 1; i < ac; ++i)  // Loop from 1 to ac - 1
        {
            MegaPhone(av[i]);
            if (i < ac - 1)           // Add a space between arguments
                std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}