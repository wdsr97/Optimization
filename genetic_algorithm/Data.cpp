#include "Permutation.h"
#include "Chromossome.h"

#include <vector>
#include <iostream>
#include "Data.h"

Data::Data(std::vector <std::vector <int> > adjacencyMatrix) :
    adjacencyMatrix(adjacencyMatrix)
{}

void Data::displayInfo()
{
    int n = this->adjacencyMatrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << ' ' << this->adjacencyMatrix[i][j];
        }
        std::cout << std::endl;
    }
}
