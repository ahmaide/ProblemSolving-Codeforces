#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
    int p1 =-1;
    int p2 =-1;
    int t = 1;
    int c1[n];
    int c2[n];
    for (int i=0 ; i<n ; i++ ){
        cin >>c1[i];
        cin >> c2[i];
    }
    for(int i=0 ; i<n && t==1 ; i++){

        if (max(c1[i], c2[i]) <= p1 || p1 == -1){
            p1 = max(c1[i], c2[i]);
            p2 = min(c1[i], c2[i]);
        }
        else{
            if (min(c1[i], c2[i]) <= p1 || p1 == -1){
                p1 = min(c1[i], c2[i]);
                p2 = max(c1[i], c2[i]);
            }
            else{
                t =0;
            }

        }
    }
    if(t==0){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}