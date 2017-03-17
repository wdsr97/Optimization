#include <vector>
#include <iostream>
#include <algorithm>
#include "Utility.h"
#include "Permutation.h"
#include "Chromossome.h"
#include "Data.h"

Chromossome::Chromossome(int genesSize)
{
	this->genes = Permutation(genesSize, 1);
	this->fitnessIsUpdated = false;
}

Permutation Chromossome::getGenes()
{
	return this->genes;
}

void Chromossome::setGenes(Permutation genes)
{
	this->genes = genes;
	this->fitnessIsUpdated = false;
}

double Chromossome::getFitness()
{
	if (this->fitnessIsUpdated == false)
		updateFitness();

	return this->fitness;
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

// n-point crossover
// To-do:
// 	Get parentsInversionTable by reference
Chromossome Chromossome::crossover(Chromossome& other)
{
	std::vector <std::vector <int> > parentsInversionTable(2);
	parentsInversionTable[0] = this->genes.getInversionTable();
	parentsInversionTable[1] = other.getGenes().getInversionTable();

	std::vector <int> shuffledIndexes(parentsInversionTable[0].size());
	for (unsigned i = 0; i < shuffledIndexes.size(); i++)
		shuffledIndexes[i] = i;
	Utility::shuffle(shuffledIndexes);

	// Isso pode ser setado no inicio do algoritmo
	int numberOfPoints = 10;
	if (numberOfPoints > (int)shuffledIndexes.size())
		numberOfPoints = shuffledIndexes.size();

	std::vector <int> points(numberOfPoints);
	for (unsigned i = 0; i < points.size(); i++)
		points[i] = shuffledIndexes[i];
	std::sort(points.begin(), points.end());
	points.emplace_back(shuffledIndexes.size());

	int l = 0;
	int k = 0;
	std::vector <int> childInversionTable;
	for (unsigned i = 0; i < points.size(); i++)
	{
		int r = points[i];
		for (int j = l; j < r; j++)
			childInversionTable.emplace_back(parentsInversionTable[k][j]);
		l = r;
		k ^= 1;
	}

	Permutation childPermutation;
	childPermutation.setInversionTable(childInversionTable);
	Chromossome child;
	child.setGenes(childPermutation);
	return child;
}

void Chromossome::updateFitness()
{
	this->fitness = 0;
	const std::vector <int>& permutation = this->genes.getPermutation();
	for (unsigned i = 0; i < permutation.size(); i++)
	{
		int u = permutation[i];
		int v = permutation[(i + 1) % permutation.size()];
		this->fitness += Data::adjacencyMatrix[u][v];
	}
	this->fitnessIsUpdated = true;
}

void Chromossome::displayData()
{
	std::cout << "\nGenes:";
	this->genes.displayData();
	std::cout << "Fitness = " << this->getFitness() << std::endl;
}
