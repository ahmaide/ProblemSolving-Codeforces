#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iomanip>
using namespace std;


void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

void swap(long long* a, long long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}

int partition (long long arr[], int low, int high)
{
    long long pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(long long arr[], long long low, long long high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    int n;
    cin >> n;
    long long v[n];
    long long u[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
        u[i]=v[i];
    }
    sort(u,u+n);
    for(int i=1; i<n ; i++){
        v[i] = v[i]+v[i-1];
        u[i] = u[i] + u[i-1];
    }
    int m;
    cin >> m;
    long long arr[m];
    int type, r, l;
    for(int i=0; i<m; i++){
        arr[i]=0;
        cin >> type;
        cin >> r;
        cin >>l;
        if(type == 1){
            if(r==1)
                arr[i]=v[l-1];
            else
                arr[i]=v[l-1] - v[r-2];
        }
        else{
            if(r==1)
                arr[i]=u[l-1];
            else
                arr[i]=u[l-1] - u[r-2];
        }
    }
    for(int i=0; i<m ; i++){
        cout << arr[i] << endl;
    }
    return 0;
}