#include <vector>
#include <limits>
#include <iomanip>
#include <iostream>
#include "Utility.h"
#include "Permutation.h"

Permutation::Permutation(int permutationSize, bool isRandom)
{
    for (int i = 0; i < permutationSize; i++)
        this->permutation.emplace_back(i);

    if (isRandom == true)
        Utility::shuffle(this->permutation, 1);

    this->permutationIsUpdated = true;
    this->inversionIsUpdated = false;
}

std::vector <int> Permutation::getPermutation()
{
    if (this->permutationIsUpdated == false)
        this->updatePermutation();

    return this->permutation;
}

void Permutation::setPermutation(std::vector <int> permutation)
{
    this->permutation = permutation;
    this->permutationIsUpdated = true;
    this->inversionIsUpdated = false;
}

std::vector <int> Permutation::getInversion()
{
    if (this->inversionIsUpdated == false)
        this->updateInversion();

    return this->inversion;
}

void Permutation::setInversion(std::vector <int> inversion)
{
    this->inversion = inversion;
    this->inversionIsUpdated = true;
    this->permutationIsUpdated = false;
}

void Permutation::updatePermutation()
{
    this->permutation.assign(this->inversion.size(), -1);
    auto inversion = this->inversion;

    for (unsigned i = 0; i < this->permutation.size(); i++)
    {
        int j = 0;
        while (inversion[i] || this->permutation[j] != -1)
        {
            inversion[i] -= (this->permutation[j] == -1);
            j++;
        }
        this->permutation[j] = i;
    }

    this->permutationIsUpdated = true;
}

void Permutation::updateInversion()
{
    this->inversion.assign(this->permutation.size(), 0);
    std::vector <int> a = this->permutation;
    this->mergeSort(a, 0, a.size() - 1);
    this->inversionIsUpdated = true;
}

void Permutation::mergeSort(std::vector <int>& a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        this->mergeSort(a, left, mid);
        this->mergeSort(a, mid + 1, right);
        this->merge(a, left, right);
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
            this->inversion[b[k]] += mid - i + 1;
        }
    }

    for (int i = 0; i < intervalSize; i++)
        a[i + left] = b[i];
}

void Permutation::displayData()
{
    auto toPrint = this->getPermutation();
    std::cout << "\n  " << std::setw(13) << "Indexes:";
    for (unsigned i = 0; i < toPrint.size(); i++) std::cout << std::setw(3) << i;
    std::cout << "\n  " << std::setw(13) << "Permutation:";
    for (auto it : toPrint) std::cout << std::setw(3) << it;
    std::cout << "\n  " << std::setw(13) << "Inversion:";
    toPrint = this->getInversion();
    for (auto it : toPrint) std::cout << std::setw(3) << it;
    std::cout << '\n';
}
