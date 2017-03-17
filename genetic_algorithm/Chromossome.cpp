#include <vector>
#include "Permutation.h"
#include "Chromossome.h"

Chromossome::Chromossome()
{
	this->fitnessIsUpdated = false;
}

Chromossome::Chromossome(int genesSize)
{
	this->genes = Permutation(genesSize);
	this->fitnessIsUpdated = false;
}

Chromossome::Chromossome(Permutation genes)
{
	this->genes = genes;
	this->fitnessIsUpdated = false;
}

void Chromossome::mutate()
{
	auto inversionTable = this->genes.getInversionTable();
	int mutationCalls = random(inversionTable.size()); // why?
	for (int i = 0; i < mutationCalls; i++)
	{
		int index = random(inversionTable.size() - 1);
		int upperBound = inversionTable.size() - index;
		inversionTable[index] = random(upperBound);
	}

	this->genes.setInversionTable(inversionTable);
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
