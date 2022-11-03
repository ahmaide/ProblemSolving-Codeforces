#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <iomanip>
#include <cstring>
#include <utility>
using namespace std;

int comp(int arr[], int p1, int p2, int n){
    int w=0;
    int which =n;
    while((10+arr[(p1+w)%n]-arr[p1])%10 == (10+arr[(p2+w)%n]-arr[p2])%10 && w<n){
        w = (w+1);
        if((10+arr[(p1+w)%n]-arr[p1])%10 < (10+arr[(p2+w)%n]-arr[p2])%10){
            which = p1;
        }
        else if((10+arr[(p1+w)%n]-arr[p1])%10 > (10+arr[(p2+w)%n]-arr[p2])%10)
            which=p2;
    }
    if(which==n)
        which =p1;
    return which;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[n];
    for(int i=0; i<n ; i++){
        arr[i] = s[i] - 48;
    }
    int curr= comp(arr, 0, 1, n);
    for(int i=2; i<n; i++){
        curr=comp(arr,curr,i, n);
    }
    int add = (10-arr[curr])%10;
    for(int i=0; i<n ; i++){
        arr[i]=(arr[i]+add)%10;
    }
    string S ="";
    for(int i = 0; i<n;i++){
        char c = arr[(i+curr)%n] + 48;
        S=S+c;
    }
    cout << S;
    return 0;
}