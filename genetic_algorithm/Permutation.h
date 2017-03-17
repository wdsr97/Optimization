#ifndef PERMUTATION_H
#define PERMUTATION_H

class Permutation
{
public:
	Permutation(int permutationSize = 0, bool isRandom = 0);
	std::vector <int> getPermutation();
	void setPermutation(std::vector <int> permutation);
	std::vector <int> getInversionTable();
	void setInversionTable(std::vector <int> inversionTable);
	void displayData();
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
