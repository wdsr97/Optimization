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
		this->updateFitness();

	return this->fitness;
}

// n-point crossover
// To-do:
// 	Get parentsInversion by reference
Chromossome Chromossome::crossover(Chromossome& other)
{
	std::vector <std::vector <int> > parentsInversion(2);
	parentsInversion[0] = this->genes.getInversion();
	parentsInversion[1] = other.getGenes().getInversion();

	std::vector <int> shuffledIndexes(parentsInversion[0].size());
	for (unsigned i = 0; i < shuffledIndexes.size(); i++)
		shuffledIndexes[i] = i;
	Utility::shuffle(shuffledIndexes);

	// Isso pode ser setado no inicio do algoritmo
	int pointCount = 10;
	if (pointCount > (int)shuffledIndexes.size())
		pointCount = shuffledIndexes.size();

	std::vector <int> points(pointCount);
	for (unsigned i = 0; i < points.size(); i++)
		points[i] = shuffledIndexes[i];
	std::sort(points.begin(), points.end());
	points.emplace_back(shuffledIndexes.size());

	int l = 0;
	int k = 0;
	std::vector <int> childInversion;
	for (unsigned i = 0; i < points.size(); i++)
	{
		int r = points[i];
		for (int j = l; j < r; j++)
			childInversion.emplace_back(parentsInversion[k][j]);
		l = r;
		k ^= 1;
	}

	// Dá pra otimizar?
	Permutation childPermutation;
	childPermutation.setInversion(childInversion);
	Chromossome child;
	child.setGenes(childPermutation);
	return child;
}

void Chromossome::mutate()
{
	auto inversion = this->genes.getInversion();
	// int mutationCount = Utility::randomIndex(inversion.size()); // why?
	int mutationCount = 1;
	for (int i = 0; i < mutationCount; i++)
	{
		int index = Utility::randomIndex(1, inversion.size() - 1);
		int upperBound = inversion.size() - index;
		inversion[index] = Utility::randomIndex(upperBound);
	}

	this->genes.setInversion(inversion);
	this->fitnessIsUpdated = false;
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
