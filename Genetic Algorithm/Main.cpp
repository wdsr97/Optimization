#include <bits/stdc++.h>
using namespace std;
#include "Permutation.cpp"

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
	while (std::cin >> n)
	{
		std::vector <int> a(n);
		for (int i = 0; i < n; i++)
			std::cin >> a[i];
		Permutation sequence(1);
		sequence.setPermutation(a);
		sequence.displayData();
	}

	return 0;
}
