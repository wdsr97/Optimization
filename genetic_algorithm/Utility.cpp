#include <time.h>
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
