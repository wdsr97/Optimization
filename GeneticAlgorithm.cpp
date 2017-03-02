#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(double mutation_rate,
								   unsigned population_size) :
	mutation_rate(mutation_rate)
{
	population = std::vector<Chromossome>(population_size);
}
