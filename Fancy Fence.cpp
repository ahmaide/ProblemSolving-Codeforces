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

int main() {
    int n;
    cin >> n;
    bool arr[n];
    for(int i=0; i<n; i++){
        double g;
        cin >> g;
        if(g<60)
            arr[i]=false;
        else{
            double m = 180/g;
            m-=1;
            m=2/m;
            double m1 = round(m);
            double k = abs(m1-m);
            if(k < 0.000001)
                arr[i]=true;
            else
                arr[i]=false;
        }
    }
    for(int i=0; i<n ; i++){
        if(arr[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}