//Analysis of methods to find GCD of two numbers

#include <iostream>
#include <time.h>
using namespace std;

long int euclid(long int m, long int n)
{
    clock_t start, end;
    start = clock();
    long int r;
    while (n!=0)
    {
        r = m % n;
        m=n;
        n=r;
    }
    end = clock();
    cout <<endl << "Time taken: " << ((end-start)/CLK_TCK) << " sec";
    return m;
}
