#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

class Chromossome
{
public:
	Chromossome();
	Chromossome(int genesSize);
	Chromossome(Permutation genes);
	Permutation getGenes();
	void setGenes(Permutation genes);
	double getFitness();
	void mutate();
	void crossover(const Chromossome& other);
	void updateFitness();
	void displayData();
private:
	Permutation genes;
	double fitness;
	bool fitnessIsUpdated;
};

#endif
