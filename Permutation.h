#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <vector>

class Permutation
{
public:
	Permutation(unsigned permutationSize);
	std::vector <int> getPermutation();
	void updatePermutation();
	void updateInversionTable();
	void setPermutation(std::vector <int> permutation);
	std::vector <int> getInversionTable();
	void setInversionTable(std::vector <int> inversionTable);
private:
	std::vector <int> permutation;
	bool permutationIsUpdated;
	std::vector <int> inversionTable;
	bool inversionTableIsUpdated;
};

#endif
