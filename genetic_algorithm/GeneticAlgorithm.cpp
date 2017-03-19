#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include "Utility.h"
#include "Permutation.h"
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
	this->elitismCount = populationSize * elitismRate;

	this->population = std::vector <Chromossome>(populationSize);
	for (unsigned i = 0; i < this->population.size(); i++)
		this->population[i] = Chromossome(geneSize);
	this->bestChromossome = this->population[0]; // Any element will do
}

std::vector <Chromossome> GeneticAlgorithm::getPopulation()
{
	return this->population;
}

void GeneticAlgorithm::setPopulation(std::vector <Chromossome> population)
{
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
	double bestFitness = 1e9; // A large number
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
	children.assign(this->population.size() - this->elitismCount, Chromossome());
	for (unsigned i = 0; i < children.size(); i++)
	{
		Chromossome& parentA = this->population[this->select()];
		Chromossome& parentB = this->population[this->select()];
		children[i] = parentA.crossover(parentB);

		double randomValue = Utility::randomIndex((int)1e6 + 1) / 1e6;
		if (randomValue <= this->mutationRate)
			children[i].mutate();
	}

	this->sortPopulation();
	for (unsigned i = 0; i < children.size(); i++)
		this->population[i] = children[i];
}

void GeneticAlgorithm::evaluate()
{
	for (auto& chromossome : this->population)
		if (chromossome.getFitness() < this->bestChromossome.getFitness())
			this->bestChromossome = chromossome;
}

void GeneticAlgorithm::report()
{
	this->bestChromossome.displayData();
}

bool GeneticAlgorithm::ChromossomeCompare(Chromossome& a, Chromossome& b)
{
	return a.getFitness() > b.getFitness();
}

void GeneticAlgorithm::sortPopulation()
{
	std::sort(
		this->population.begin(),
		this->population.end(),
		std::bind(
			&GeneticAlgorithm::ChromossomeCompare,
			this,
			std::placeholders::_1,
			std::placeholders::_2
		)
	);
}
