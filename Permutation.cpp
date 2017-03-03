#include "Permutation.h"

Permutation::Permutation(unsigned permutationSize)
{
	for (unsigned i = 0; i < permutationSize; i++)
	{
		this->permutation.emplace_back(i);
		this->inversionTable.emplace_back(0);
	}

	this->permutationIsUpdated = true;
	this->inversionTableIsUpdated = true;
}

std::vector <int> Permutation::getPermutation()
{
	if (this->permutationIsUpdated == false)
	{
		updatePermutation();
	}

	return this->permutation;
}

void Permutation::setPermutation(std::vector <int> permutation)
{
	this->permutation = permutation;
	this->inversionTableIsUpdated = false;
}

std::vector <int> Permutation::getInversionTable()
{
	if (this->inversionTableIsUpdated == false)
	{
		updateInversionTable();
	}

	return this->inversionTable;
}

void Permutation::setInversionTable(std::vector <int> inversionTable)
{
	this->inversionTable = inversionTable;
	this->permutationIsUpdated = false;
}
