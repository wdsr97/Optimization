#include "Permutation.h"

Permutation::Permutation(int permutationSize)
{
	for (int i = 0; i < permutationSize; i++)
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

void Permutation::updatePermutation()
{
	this->permutation.assign(this->inversionTable.size(), -1);

	for (unsigned i = 0; i < this->permutation.size(); i++)
	{
		int j = 0;
		while (this->inversionTable[i] || this->inversionTable[i] != -1)
		{
			if (this->permutation[j] == -1)
				this->inversionTable[i]--;
		}
		this->permutation[j] = i;
	}

	this->permutationIsUpdated = true;
}

void Permutation::updateInversionTable()
{
	this->inversionTable.assign(this->permutation.size(), 0);
	std::vector <int> a = this->permutation;
	mergeSort(a, 0, a.size() - 1);
	this->inversionTableIsUpdated = true;
}

void Permutation::mergeSort(std::vector <int>& a, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, right);
	}
}

void Permutation::merge(std::vector <int>& a, int left, int right)
{
	int intervalSize = right - left + 1;
	std::vector <int> b(intervalSize);
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;

	for (int k = 0; k < intervalSize; k++)
	{
		int ai = (i > mid ? std::numeric_limits <int>::max() : a[i]);
		int aj = (j > right ? std::numeric_limits <int>::max() : a[j]);

		if (ai < aj)
		{
			b[k] = a[i++];
		}
		else
		{
			b[k] = a[j++];
			this->inversionTable[b[k]] += mid - i + 1;
		}
	}

	for (int i = 0; i < intervalSize; i++)
	{
		a[i + left] = b[i];
	}
}

void Permutation::displayData()
{
	std::cout << "\n--------------------";
	std::cout << "\nPermutation:\n";
	auto toPrint = this->getPermutation();
	for (unsigned i = 0; i < toPrint.size(); i++)
	{
		std::cout << std::setw(3) << toPrint[i];
	}
	std::cout << "\nInversion Table:\n";
	toPrint = this->getInversionTable();
	for (unsigned i = 0; i < toPrint.size(); i++)
	{
		std::cout << std::setw(3) << toPrint[i];
	}
	std::cout << "\n--------------------\n";
}
