#include <iostream>
#include <time.h>
using namespace std;

void disp(int arr[], int n)
{
        for (int i=0; i<n; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
}

void iSort(int arr[], int n)
{
        for (int i=1; i<n; i++)
        {
                int cur = arr[i];
                int j=i-1;
                while (j>=0 && arr[j]>cur)
                {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1]=cur;
        }
        cout << "Insertion sort:\n";
        disp(arr,n);
}

void bSort(int arr[], int n)
{
        for (int i=0; i<n-1; i++)
        {
                for (int j=0; j<n-i-1; j++)
                        {
                                if (arr[j] > arr[j+1])
                                {
                                        int temp = arr[j+1];
                                        arr[j+1] = arr[j];
                                        arr[j] = temp;
                                }
                        }
        }
        cout << "Bubble sort:\n";
        disp(arr,n);
}

int main()
{
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        int arr1[n], arr2[n];
        for (int i=0; i<n; i++)
        {
                int x;
                cin >> x;
                arr1[i]=x;
                arr2[i]=x;
        }
        clock_t s1,s2,e1,e2;
        s1 = clock();
        bSort(arr2,n);
        e1 = clock();
        s2 = clock();
        iSort(arr1,n);
        e2 = clock();
        float t1,t2;
        t1 = (e1-s1)*1.0/CLOCKS_PER_SEC;
        t2 = (e2-s2)*1.0/CLOCKS_PER_SEC;
        cout << "Time by insertion sort: " << t1 << endl;
        cout << "Time by bubble sort: " << t2 << endl;
        return 0;
}
