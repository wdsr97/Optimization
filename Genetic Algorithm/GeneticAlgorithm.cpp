#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(double mutation_rate,
								   unsigned population_size) :
	mutation_rate(mutation_rate)
{
	population = std::vector<Chromossome>(population_size);
}

int GeneticAlgorithm::select()
{
	// return selection::
	return selection::tournamentSelection(2);
}

void GeneticAlgorithm::newGeneration()
{
	std::vector <Chromossome> newPopulation;
	for (unsigned i = 0; i < this->population.size(); i++)
	{
		int index[2];
		index[0] = selection();
		index[1] = selection();

		Chromossome parents[2];
		parents[0] = this->population[index[0]];
		parents[1] = this->population[index[1]];

		Chromossome child = parents[0].crossover(parents[1]);

		if (rand() % 101 <= this->mutation_rate)
		{
			child.mutate();
		}

		newPopulation[i] = child;
	}

	this->population = newPopulation;
}
