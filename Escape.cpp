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
    double vp, vd, t, f,c;
    cin >> vp;
    cin >> vd;
    cin >> t;
    cin >> f;
    cin >> c;
    int sum=0;
    double dist=vp*t;
    while(dist<c){
        if(vp>=vd)
            break;
        t=dist/(vd-vp);
        dist=vd*t;
        if(dist<c)
            sum++;
        t=dist/vd;
        dist+=(t*vp);
        dist+=(vp*f);
    }
    cout << sum;
    return 0;
}