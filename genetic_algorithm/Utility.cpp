#include <time.h>
#include "Utility.h"

unsigned long long a = 4294957665u;
static long long const int v = 4294967295u;

inline unsigned long long Utility::random()
{
    unsigned long long x = time(NULL);
    x = a * (x & v) + (x >> 32);
    return x;
}

inline int Utility::randomIndex(int low, int high)
{
    if (high == -1)
    {
        high = low;
        low = 0;
    }
    int index = (random() % (high - low)) + low;
    return index;
}
