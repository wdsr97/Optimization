#include <bits/stdc++.h>
#include "Utility.h"
#include "Permutation.h"
#include "Data.h"
#include "Chromossome.h"
#include "GeneticAlgorithm.h"



int main()
{
	#defining constants of the program:
	int MAX_ITER = 2;
	int POP_SIZE = 1000;
	float MUT_RATE = 0.07;
	float ELIT_RATE = 0.15;
	int MAX_GEN = 200;
	execute(MAX_ITER, POP_SIZE, MUT_RATE, ELIT_RATE, MAX_GEN);
}

int execute(int MAX_ITER,int  POP_SIZE, float MUT_RATE,float ELIT_RATE, int MAX_GEN)
{
    int n;
    std::cin >> n;
    Data::adjacencyMatrix =
            std::vector <std::vector <int> >(n, std::vector <int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> Data::adjacencyMatrix[i][j];

    for (int i = 0; i < MAX_ITER; i++)
    {
        std::cout << "Iteration " << i+1 << ":\n";
        GeneticAlgorithm ga(POP_SIZE, n, MUT_RATE, ELIT_RATE);
        ga.evaluate();
        double best = ga.getBestChromossome().getFitness();
        for (int t = 0; t < MAX_GEN; t++) {
            ga.newGeneration();
            ga.evaluate();
            double curBest = ga.getBestChromossome().getFitness();
            if (curBest < best)
            {
                t = 0;
                best = curBest;
            }
        }
        ga.report();
        std::cout << std::endl;
    }
    return 0;
}
