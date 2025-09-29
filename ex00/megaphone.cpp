/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:44:45 by mradouan          #+#    #+#             */
/*   Updated: 2025/09/21 12:40:44 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    toUpperCase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'A')
            str[i] += 32;
        i++;
    }
}


int main(int argc, char **argv)
{
    int i;
    std::string concat;
    
    i = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (argv[i])
    {
        concat += argv[i];
        i++;    
    }
    i = 0;
    while (concat[i])
    {
        concat[i] = std::toupper(concat[i]);
        i++;
    }
    std::cout << concat << std::endl;
}
