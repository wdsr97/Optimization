#ifndef UTILITY_H
#define UTILITY_H

class Utility
{
public:
    static unsigned long long int x;
    static unsigned long int a;
    static long long const int v;
    static unsigned long long int random();
    static int randomIndex(int low, int high = -1);
    static void swap(int& a, int& b);
    static void shuffle(std::vector <int>& a, int low = 0, int high = -1);
private:
    Utility() {}
};

#endif
