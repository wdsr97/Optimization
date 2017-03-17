#include <vector>
#include <iostream>
#include "Data.h"

std::vector <std::vector <int> > Data::adjacencyMatrix =
    std::vector <std::vector <int> >();

void Data::displayInfo()
{
    int n = adjacencyMatrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << ' ' << adjacencyMatrix[i][j];
        }
        std::cout << std::endl;
    }
}
