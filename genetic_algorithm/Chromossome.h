#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

class Chromossome
{
public:
	Chromossome();
	Chromossome(int);
	Chromossome(Permutation);
	Permutation getGenes();
	void mutate();
	void crossover(const Chromossome& other);
	void computeFitness();
	void setGenes(Permutation genes);
	double getFitness();
private:
	Permutation genes;
	double fitness;
	bool fitnessIsUpdated;
};

#endif
