#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;


void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    long long n,k;
    cin >> n;
    cin >> k;
    long long w = (k*(k+1))/2;
    w = w - k + 1;
    long double w2 = w - n;
    if(w2<0)
        cout << "-1";
    else if(w2==0)
        cout << k-1;
    else{
        long double w3 = (0.5+sqrt(0.25 + (2*w2)));
        w = floor(w3);
        w = k - w;
        cout << w;
    }
    return 0;
}