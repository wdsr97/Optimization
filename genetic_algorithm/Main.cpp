#include <bits/stdc++.h>
using namespace std;
#include "Utility.h"
#include "Permutation.h"
// #include "GeneticAlgorithm.cpp"
// #include "Chromossome.cpp"

class Tester
{
public:
	static bool testPermutation()
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

	static void testRNG()
	{
		std::cout << '\n';
		for (int i = 0; i < 10; i++)
			std::cout << Utility::random() << '\n';
		std::cout << '\n';
		for (int i = 0; i < 10; i++)
			std::cout << Utility::randomIndex(i, i + 10) << '\n';
		std::cout << '\n';
	}
};

int main()
{

	return 0;
}
