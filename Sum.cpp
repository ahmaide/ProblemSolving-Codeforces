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
    for(int i=0; i<n ; i++){
        int a,b,c;
        cin >>a;
        cin >> b;
        cin >> c;
        int w = max(a,b);
        int w0= min(a,b);
        int x=max(w,c);
        int x0=min(w,c);
        if(x0+w0==x)
            arr[i]=true;
        else
            arr[i]=false;
    }
    for(int i=0; i<n ; i++){
        if(arr[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}