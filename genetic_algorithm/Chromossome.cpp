#include <vector>
#include <iostream>
#include "Utility.h"
#include "Permutation.h"
#include "Chromossome.h"

Chromossome::Chromossome(int genesSize)
{
	this->genes = Permutation(genesSize, 1);
	this->fitnessIsUpdated = false;
}

void Chromossome::mutate()
{
	auto inversionTable = this->genes.getInversionTable();
	int mutationCalls = Utility::randomIndex(inversionTable.size()); // why?
	for (int i = 0; i < mutationCalls; i++)
	{
		int index = Utility::randomIndex(inversionTable.size() - 1);
		int upperBound = inversionTable.size() - index;
		inversionTable[index] = Utility::randomIndex(upperBound);
	}

	this->genes.setInversionTable(inversionTable);
	this->fitnessIsUpdated = false;
}

void Chromossome::crossover(const Chromossome& other)
{
	// Crossover procedure
	this->fitnessIsUpdated = false;
}

void Chromossome::updateFitness()
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
		updateFitness();
	}

	return this->fitness;
}

void Chromossome::displayData()
{
	std::cout << "\n--------------------";
	std::cout << "\nGenes:\n";
	this->genes.displayData();
	std::cout << this->getFitness() << std::endl;
	std::cout << "\n--------------------\n";
}
