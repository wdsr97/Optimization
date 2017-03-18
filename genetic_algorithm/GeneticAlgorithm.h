#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(
		int populationSize,
		int geneSize,
		double mutationRate,
		double elitismRate
	);
	std::vector <Chromossome> getPopulation();
	void setPopulation(std::vector <Chromossome> population);
	Chromossome getBestChromossome();
	double getMutationRate();
	void setMutationRate(double mutationRate);
	double getElitismRate();
	void setElitismRate(double elitismRate);
	void newGeneration();
	void evaluate();
	int run(int generationCount)
private:
	int select();
	std::vector <Chromossome> population;
	Chromossome bestChromossome;
	double mutationRate;
	double elitismRate;
	int elitism;
};

#endif
