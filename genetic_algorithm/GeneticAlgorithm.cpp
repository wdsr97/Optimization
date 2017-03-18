#include <vector>
#include <algorithm>
#include "Utility.h"
#include "Chromossome.h"
#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(
		int populationSize,
		int geneSize,
		double mutationRate,
		double elitismRate
	)
{
	this->mutationRate = mutationRate;
	this->elitismRate = elitismRate;
	this->elitism = populationSize * (elitismRate / 100.0);

	this->population = std::vector <Chromossome>(populationSize);
	for (unsigned i = 0; i < this->population.size(); i++)
		this->population[i] = Chromossome(geneSize);
	std::sort(this->population.begin(), this->population.end());
}

std::vector <Chromossome> GeneticAlgorithm::getPopulation()
{
	return this->population;
}

void GeneticAlgorithm::setPopulation(std::vector <Chromossome> population)
{
	std::sort(population.begin(), population.end());
	this->bestChromossome = population[population.size() - 1];
	this->population = population;
}

Chromossome GeneticAlgorithm::getBestChromossome()
{
	return this->bestChromossome;
}

double GeneticAlgorithm::getMutationRate()
{
	return this->mutationRate;
}

void GeneticAlgorithm::setMutationRate(double mutationRate)
{
	this->mutationRate = mutationRate;
}

double GeneticAlgorithm::getElitismRate()
{
	return this->elitismRate;
}

void GeneticAlgorithm::setElitismRate(double elitismRate)
{
	this->elitismRate = elitismRate;
}

int GeneticAlgorithm::select()
{
	int bestFitness = 1e9; // A large number
	int bestIndex = 0;
	int k = 2; // tournamentSelection

	for (int i = 0; i < k; i++)
	{
		int index = Utility::randomIndex(this->population.size());
		Chromossome& selected = this->population[index];

		if (selected.getFitness() < bestFitness)
		{
			bestFitness = selected.getFitness();
			bestIndex = index;
		}
	}
	return bestIndex;
}

void GeneticAlgorithm::newGeneration()
{
	std::vector <Chromossome> children;
	children.assign(this->population.size() - this->elitism, Chromossome());
	for (unsigned i = 0; i < children.size(); i++)
	{
		Chromossome& parentA = this->population[this->select()];
		Chromossome& parentB = this->population[this->select()];
		children[i] = parentA.crossover(parentB);

		double randomValue = Utility::randomIndex((int)1e6 + 1) / 1e6;
		if (randomValue <= this->mutationRate)
			children[i].mutate();
	}

	std::sort(this->population.begin(), this->population.end());
	for (unsigned i = 0; i < children.size(); i++)
		this->population[i] = children[i];
}

void GeneticAlgorithm::evaluate()
{
	// this->population should always be ordered when get here
	this->bestChromossome = this->population[this->population.size() - 1];
}
