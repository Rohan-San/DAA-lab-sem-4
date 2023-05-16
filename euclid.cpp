#include <iostream>
#include <time.h>
using namespace std;

int gcdByDivision(int a, int b)
{
        if (b==0)
                return a;
        return gcdByDivision(b,a%b);
}

int gcd(int a, int b)
{
        if (a==b)
                return a;
        if (a<b){
                b=b-a;
                return gcd(a,b);
        }
        if (a>b){
                a=a-b;
                return gcd(a,b);
        }
}

int main()
{
        clock_t start1,start2,end1,end2;
        int a,b,c;
        cout << "Enter 2 numbers to get GCD: "<< endl;
        cin >> a >> b;
        start1 = clock();
        gcd(a,b);
        end1 = clock();
        start2 = clock();
        gcdByDivision(a,b);
        end2 = clock();

        cout << "The GCD by subtraction algorithm is: " << gcd(a,b) << endl;
        cout << "The GCD by division lagorithm is: " << gcdByDivision(a,b) << endl;
        cout << "Time taken by subtraction algo: " << (double)(end1-start1)/CLOCKS_PER_SEC << endl;
        cout << "Time taken by division algo: " << (double)(end2-start2)/CLOCKS_PER_SEC << endl;
        return 0;
}
