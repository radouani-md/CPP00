#include <iostream>

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
