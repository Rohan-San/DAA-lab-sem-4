//ERROR!

#include <iostream>
#include <math.h>
using namespace std;

#define a 10

int * primeFactor(int x)
{
    int pf[a],j=0;
	while (x % 2 == 0)
	{
		pf[j]=2;
		j++;
		x = x/2;
	}

	for (int i = 3; i <= sqrt(x); i = i + 2)
	{
		while (x % i == 0)
		{
			pf[j]=i;
			j++;
			x = x/i;
		}
	}
	
	if (x > 2)
		pf[j]=x;
		j++;
	
	for (int i=0;i<j;i++)
	{
	    cout<< pf[i] << " ";
	}
	return pf;
}

void comp (arr1[], arr2[])
{
    int k=0, arr3[a];
    for (int i=0; i<sizeof(arr1);i++)
    {
        for (int j=0; j< sizeof(arr2); j++)
        {
            if arr1[i]==arr2[j]
            {
                arr3[k]=arr1[i];
                k++;
            }
        }
    }
}

int main()
{
	int m, n, *arrm, *arrn;
	cin >> m >> n;
	arrm = primeFactor(m);
	cout << endl;
	arrn = primeFactor(n);
	cout << endl;
	return 0;
}
