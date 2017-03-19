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
	void report();
private:
	void sortPopulation();
	bool ChromossomeCompare(Chromossome& a, Chromossome& b);
	int select();
	std::vector <Chromossome> population;
	Chromossome bestChromossome;
	double mutationRate;
	double elitismRate;
	int elitismCount;
};

#endif
