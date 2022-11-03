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
int val(int beg, int en, int k, int sum){
    int s=0;
    int w=1;
    if(beg==en)
        return beg;
    else{
        int mid = (beg+en)/2;
        for(int i=0; w>0 && s<sum; i++){
            w=mid/pow(k,i);
            s+=w;
        }
        if(s>=sum){
            return val(beg, mid, k, sum);
        }
        else{
            if(mid==beg)
                return en;
            else
                return val(mid, en, k, sum);
        }
    }
}

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
    int i = val(0, n, k, n);
    cout << i;
    return 0;
}