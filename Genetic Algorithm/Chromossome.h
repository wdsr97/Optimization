#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

#include <vector>
#include "Permutation.h"

class Chromossome
{
public:
	Chromossome();
	Permutation getGenes();
	void mutate();
	void crossover(const Chromossome& other);
	void computeFitness();
	void setGenes(Permutation genes);
	int getFitness();
private:
	Permutation genes;
	int fitness;
	bool fitnessIsUpdated;
};

#endif
