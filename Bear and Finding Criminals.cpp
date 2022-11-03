#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    int n;
    cin >> n;
    int loc;
    cin >> loc;
    loc--;
    int arr [n];
    for(int i=0 ; i<n ;i++){
        cin >> arr[i];
    }
    int sum=0;
    if (arr[loc] == 1)
        sum++;
    for(int g1 = loc-1 ,g2=loc+1 ; g1>=0 || g2<n ; g1-- , g2++){
        if(g1>=0 && g2<n){
            if(arr[g1]==1 && arr[g2]==1)
                sum+=2;
        }
        else if(g1>=0 && g2>=n){
            if(arr[g1]==1)
                sum+=1;
        }
        else if(g1<0 && g2<n){
            if(arr[g2]==1)
                sum+=1;
        }
    }
    cout << sum;
    return 0;
}