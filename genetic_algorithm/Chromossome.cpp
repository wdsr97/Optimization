#include <vector>
#include "Permutation.h"
#include "Chromossome.h"

Chromossome::Chromossome() :
	fitnessIsUpdated(false)
{}

Chromossome::Chromossome(int genesSize)
{
	this->genes = Permutation(genesSize);
}

Chromossome::Chromossome(Permutation genes) :
	genes(genes)
{}

void Chromossome::mutate()
{
	// Mutate procedure
	this->fitnessIsUpdated = false;
}

void Chromossome::crossover(const Chromossome& other)
{
	// Crossover procedure
	this->fitnessIsUpdated = false;
}

void Chromossome::computeFitness()
{
	this->fitness = 0;

	// Compute procedue
	this->fitnessIsUpdated = true;
}

void Chromossome::setGenes(Permutation genes)
{
	this->genes = genes;
	this->fitnessIsUpdated = false;
}

double Chromossome::getFitness()
{
	if (this->fitnessIsUpdated == false)
	{
		computeFitness();
	}

	return this->fitness;
}
