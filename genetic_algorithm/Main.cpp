#include <bits/stdc++.h>
using namespace std;
#include "Permutation.h"
// #include "GeneticAlgorithm.cpp"
// #include "Chromossome.cpp"

inline namespace utility
{
	// class RandomNumberGenerator
	// // x = a * (x & v) + (x >> 32)
	// {
	// public:
	// 	static inline unsigned long long random()
	// 	{
	// 		x = a * (x & v) + (x >> 32);
	// 		return x;
	// 	}
	// private:
	// 	unsigned long long x = time(NULL);
	// 	unsigned long long a = 4294957665u;
	// 	static long long const int v = 4294967295u;
	// };

	// template <typename T>
	// void shuffle(std::vector <T>& elements)
	// {
	// 	for (unsigned i = 0; i < elements.size(); i++)
	// 	{
	// 		int index = rand
	// 	}
	// }
}

class Tester
{
	static bool testPermutation();
};

bool Tester::testPermutation()
{
    int factorial = 1;
    for (int n = 1; n < 9; n++)
    {
        std::vector <int> a(n);
        for (int i = 0; i < n; i++) a[i] = i;
        std::set <std::vector <int> > all;
        Permutation x(n), y(n);

        do {
            x.setPermutation(a);
            y.setInversionTable(x.getInversionTable());
            if (x.getPermutation() != y.getPermutation()) return 0;
            all.insert(y.getInversionTable());
        } while (std::next_permutation(a.begin(), a.end()));

        factorial *= n;
        if ((int)all.size() != factorial) return 0;
    }
    return 1;
}

int main()
{

	return 0;
}
