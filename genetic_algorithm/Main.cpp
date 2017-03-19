#include <bits/stdc++.h>
#include "Utility.h"
#include "Permutation.h"
#include "Data.h"
#include "Chromossome.h"
#include "GeneticAlgorithm.h"

class Tester
{
public:
	static bool testPermutation()
	{
		int factorial = 1;
	    for (int n = 1; n < 9; n++)
	    {
	        std::vector <int> a(n);
	        for (int i = 0; i < n; i++) a[i] = i;
	        std::set <std::vector <int> > all;
	        Permutation x(n), y(n);

	        do {
	            x.setPermutation(a);
	            y.setInversion(x.getInversion());
	            if (x.getPermutation() != y.getPermutation()) return 0;
	            all.insert(y.getInversion());
	        } while (std::next_permutation(a.begin(), a.end()));

	        factorial *= n;
	        if ((int)all.size() != factorial) return 0;
	    }
	    return 1;
	}

	static void testRNG()
	{
		std::cout << '\n';
		for (int i = 0; i < 10; i++)
			std::cout << Utility::random() << '\n';
		std::cout << '\n';
		for (int i = 0; i < 10; i++)
			std::cout << Utility::randomIndex(i, i + 10) << '\n';
		std::cout << '\n';
	}
};

int main()
{
	int n;
	std::cin >> n;
	Data::adjacencyMatrix =
		std::vector <std::vector <int> >(n, std::vector <int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> Data::adjacencyMatrix[i][j];

	for (int i = 0; i < 1; i++)
	{
		GeneticAlgorithm ga(1000, n, 0.07, 0.15);
		ga.evaluate();
		double best = ga.getBestChromossome().getFitness();
		for (int t = 0; t < 200; t++)
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
	}


	return 0;
}
