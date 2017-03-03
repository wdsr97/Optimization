#ifndef CHROMOSSOME_H
#define CHROMOSSOME_H

#include <vector>

class Chromossome
{
public:
	Chromossome();
	std::vector<int> getGenes();
	void mutate();
	void crossover(const Chromossome& other);
	void computeFitness();
	void setGenes(std::vector<int> genes);
	int getFitness();
private:
	std::vector <int> genes;
	int fitness;
	bool fitnessOutdated;
};

#endif
