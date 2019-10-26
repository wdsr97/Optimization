#ifndef PERMUTATION_H
#define PERMUTATION_H

class Permutation
{
public:
    Permutation(int permutationSize = 0, bool isRandom = 0);
    std::vector <int> getPermutation();
    void setPermutation(std::vector <int> permutation);
    std::vector <int> getInversion();
    void setInversion(std::vector <int> inversion);
    void displayData();
private:
    void updatePermutation();
    void updateInversion();
    void mergeSort(std::vector <int>&, int, int);
    void merge(std::vector <int>&, int, int);
    std::vector <int> permutation;
    bool permutationIsUpdated;
    std::vector <int> inversion;
    bool inversionIsUpdated;
};

#endif
