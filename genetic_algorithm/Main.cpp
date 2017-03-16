#include <bits/stdc++.h>
using namespace std;
#include "Permutation.cpp"
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

int main()
{
	int n;
	cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) a[i] = i;

	Permutation foo(n), bar(n);
	std::set <std::vector <int> > foobar;

	do {
		foo.setPermutation(a);
		bar.setInversionTable(foo.getInversionTable());
		if (foo.getPermutation() != bar.getPermutation())
		{
			std::cout << "Error on list:\n";
			for (auto it : a) std::cout << ' ' << it;
			std::cout << '\n';
		}
		foobar.insert(bar.getInversionTable());
	} while (std::next_permutation(a.begin(), a.end()));

	std::cout << foobar.size() << '\n';

	return 0;
}
