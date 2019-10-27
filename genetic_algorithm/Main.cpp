#include <bits/stdc++.h>
#include "Utility.h"
#include "Permutation.h"
#include "Data.h"
#include "Chromossome.h"
#include "GeneticAlgorithm.h"

#define MAX_ITER 2
#define POP_SIZE 1000
#define MUT_RATE 0.07
#define ELIT_RATE 0.15
#define MAX_GEN 200

int max_iter, pop_size, max_gen;
double mut_rate, elit_rate;

void process_command_line_args(int argc, char*argv[])
{
    (argc > 1 && isdigit(*argv[1])) ? max_iter = atoi(argv[1])  : max_iter = MAX_ITER;
    (argc > 2 && isdigit(*argv[2])) ? pop_size = atoi(argv[2])  : pop_size = POP_SIZE;
    (argc > 3 && isdigit(*argv[3])) ? mut_rate = atof(argv[3])  : mut_rate = MUT_RATE;
    (argc > 4 && isdigit(*argv[4])) ? elit_rate = atof(argv[4]) : elit_rate = ELIT_RATE;
    (argc > 5 && isdigit(*argv[5])) ? max_gen = atoi(argv[5])   : max_gen = MAX_GEN;
}

int main(int argc, char *argv[])
{
    //up to five constants can be optionally passed as command-line args
    process_command_line_args(argc, argv);
    int n;
    std::cin >> n;
    Data::adjacencyMatrix =
        std::vector <std::vector <int> >(n, std::vector <int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> Data::adjacencyMatrix[i][j];
        }
    }
    for (int i = 0; i < max_iter; i++)
    {
        std::cout << "Iteration " << i+1 << ":\n";
        GeneticAlgorithm ga(pop_zie, n, mut_rate, elit_rate);
        ga.evaluate();
        double best = ga.getBestChromossome().getFitness();
        for (int t = 0; t < max_gen; t++) 
        {
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
