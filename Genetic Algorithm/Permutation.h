#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <vector>
#include <limits>

class Permutation
{
public:
	Permutation(int permutationSize);
	std::vector <int> getPermutation();
	void setPermutation(std::vector <int> permutation);
	std::vector <int> getInversionTable();
	void setInversionTable(std::vector <int> inversionTable);
private:
	void updatePermutation();
	void updateInversionTable();
	void mergeSort(std::vector <int>&, int, int);
	void merge(std::vector <int>&, int, int);
	std::vector <int> permutation;
	bool permutationIsUpdated;
	std::vector <int> inversionTable;
	bool inversionTableIsUpdated;
};

#endif
