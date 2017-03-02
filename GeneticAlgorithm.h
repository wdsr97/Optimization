#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <vector>
#include "Chromossome.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(double mutation_rate, unsigned population_size);
	void newGeneration();
	void evaluate();
private:
	std::vector <Chromossome> population;
	Chromossome best_chromossome;
	double mutation_rate;
};

#endif
