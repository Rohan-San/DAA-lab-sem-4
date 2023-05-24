#include <iostream>
#include <time.h>
using namespace std;

int BinarySearch(int a[], int start, int end, int item, int iter)
{
    int i, mid;
    cout<<"\niteration "<<iter+1;
    iter++;
    mid = start + (end-start+1)/2;
    if(item > a[end] || item < a[start] || mid == end) {
       cout<<"\nNot found";
       return iter;
    }
    else if(item == a[mid]) {
      cout<<"\n item found at "<<mid<<" index.";
      return iter;
    }
    else if(item == a[start]) {
      cout<<"\n item found at "<<start<<" index.";
      return iter;
    }
    else if(item == a[end]) {
      cout<<"\n item found at "<<end<<" index.";
      return iter;
    }
    else if(item > a[mid])
         BinarySearch(a, mid, 9, item, iter);
    else
         BinarySearch(a, start, mid, item, iter);
    return 0;
}

int LinearSearch(int a[], int n, int item)
{
      int i;
      for(i = 0; i < n; i++) {
         cout<<"\niteration "<<i+1;
         if(a[i] == item) {
            cout<<"\n item found at "<<i<<" index.";
         return i+1;
         }
      }
   cout<<"\nNot found";
   return 0;
}

int main()
{
        clock_t start1, end1, start2, end2;
        int n, i, B, L, a[10]={2, 7, 14, 24, 26, 35, 38, 41, 49, 53};
        cout<<"\nEnter the element to be searched: ";
        cin>>n;
        cout<<"\n\nBinary Search :";
        start1 = clock();
        B = BinarySearch(a, 0, 9, n, 0);
        end1 = clock();
        cout << "\nTime taken by binary search: " << (double)(end1-start1)/CLOCKS_PER_SEC << endl;
        cout<<"\n\nLinear Search :";
        start2 = clock();
        L = LinearSearch(a, 10, n);
        end2 = clock();
        cout << "\nTime taken by linear search: " << (double)(end2-start2)/CLOCKS_PER_SEC << endl;
        if(L > B)
                cout<<"\n\nBinary search is better for this search.\n";
        else if(L < B)
                cout<<"\n\nLinear search is better for this search.\n";
        else
                cout<<"\n\nBoth are equally efficient for this search.\n";

        return 0;
}

