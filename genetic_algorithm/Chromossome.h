#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

class Chromossome
{
public:
	Chromossome(int genesSize = 0);
	Permutation getGenes();
	void setGenes(Permutation genes);
	double getFitness();
	void mutate();
	void crossover(Chromossome& other);
	void updateFitness();
	void displayData();
private:
	Permutation genes;
	double fitness;
	bool fitnessIsUpdated;
};

#endif
