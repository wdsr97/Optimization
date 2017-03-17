#include <time.h>
#include <vector>
#include "Utility.h"

unsigned long long int Utility::x = time(NULL);
unsigned long int Utility::a = 4294957665u;
long long const int Utility::v = 4294967295u;

unsigned long long int Utility::random()
{
    x = a * (x & v) + (x >> 32);
    return x;
}

int Utility::randomIndex(int low, int high)
{
    if (high == -1)
    {
        high = low;
        low = 0;
    }
    int index = (random() % (high - low)) + low;
    return index;
}

void Utility::swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void Utility::shuffle(std::vector <int>& a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int index = randomIndex(i, n);
        swap(a[i], a[index]);
    }
}
