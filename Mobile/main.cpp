//Author : Iskander Sergazin isergazin@edu.hse.ru (used two different accounts)
#include <iostream>

int main()
{
    std::string str;
    int counter = 0;
    std::cin >> str;
    for(int i = 0; i < str.length();)
    {
        if(isalpha(str[i]))
        {
            while(isalpha(str[i]))
            {
                i++;
                counter ++;
            }
        }
        else
        {
            std::string number;
            while(!isalpha(str[i]))
            {
                number += str[i];
                i++;
            }
            counter += std::stoi(number) - 1;
        }
    }
    std::cout << counter;
    return 0;
}

