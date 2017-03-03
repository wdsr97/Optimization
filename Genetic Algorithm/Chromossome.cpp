#include "Chromossome.h"

Chromossome::Chromossome() :
	fitnessOutdated(true)
{}

void Chromossome::mutate()
{
	// Mutate procedure
	this->fitnessOutdated = true;
}

void Chromossome::crossover(const Chromossome& other)
{
	// Crossover procedure
	this->fitnessOutdated = true;
}

void Chromossome::computeFitness()
{
	this->fitness = 0;
	for (unsigned i = 1; i < this->genes.size(); i++)
	{
		int u = this->genes[i - 1];
		int v = this->genes[i];
		// Como pegar a matriz de adjacência???
	}

	this->fitnessOutdated = false;
}

void Chromossome::setGenes(std::vector <int> genes)
{
	this->genes = genes;
	this->fitnessOutdated = true;
}

int Chromossome::getFitness()
{
	if (this->fitnessOutdated == true)
	{
		computeFitness();
	}

	return this->fitness;
}
