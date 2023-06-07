#include <iostream>
#include <time.h>
using namespace std;

void merge(int *a, int low, int high, int mid)
{
        int i, j, k, temp[100];
        i = low;
        k = 0;
        j = mid + 1;
        while (i<=mid && j<=high)
        {
                if (a[i] < a[j])
                {
                        temp[k] = a[i];
                        k++;
                        i++;
                }
                else
                {
                        temp[k] = a[j];
                        k++;
                        j++;
                }
        }
        while (i<=mid)
        {
                temp[k] = a[i];
                k++;
                i++;
        }
        while (j<=high)
        {
                temp[k] = a[j];
                k++;
                j++;
        }
        for (i=low; i<=high; i++)
        {
                a[i] = temp[i-low];
        }
}

void mergeSort(int *a, int low, int high)
{
        int mid;
        if (low < high)
        {
                mid = (low+high)/2;
                mergeSort(a, low, mid);
                mergeSort(a, mid+1, high);
                merge(a, low, high, mid);
        }
}

int main()
{
        clock_t start,end;
        int n, i;
        cout << "Enter no. of elements to sort: ";
        cin >> n;
        int arr[n];
        cout << "Enter elements: ";
        for (i=0; i<n; i++)
        {
                cin >> arr[i];
        }
        start = clock();
        mergeSort(arr, 0, n-1);;
        end = clock();
        cout << "Sorted data: ";
        for (i=0; i<n; i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Time taken: " << (double)(end-start)/CLOCKS_PER_SEC << endl;
        return 0;
}
