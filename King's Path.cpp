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

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

std::map<std::pair<int,int>, long long> mapp;
vector<pair<int, int>> arr;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    int x1, y1, x2, y2, n;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    cin >> n;
    for(int i=0; i<n ; i++){
        int r,a,b;
        cin >> r;
        cin >> a;
        cin >> b;
        for(int j=a ; j<=b ; j++){
            mapp[{r,j}]=-1;
        }
        mapp[{x1, y1}]=0;
    }
    arr.push_back({x1, y1});
    int j1=-1;
    int k1=-1;
    int dist=0;
    for(int i=0 ; i<arr.size() && (j1!=x2 || k1!= y2) && dist<100000; i++){
        int x = arr[i].first;
        int y= arr[i].second;
        dist = mapp[{x,y}];
        for(int j= x-1 ; j<=x+1 && (j1!=x2 || k1!= y2) ; j++){
            for(int k= y-1 ; k<=y+1 && (j1!=x2 || k1!= y2); k++){
                if((j!=x || k!=y) && mapp.find({j,k}) != mapp.end()){
                    if(mapp[{j,k}] == -1){
                        mapp[{j,k}] = dist+1;
                        arr.push_back({j,k});
                        j1=j;
                        k1=k;
                    }
                }
            }
        }
    }
    cout << mapp[{x2, y2}];

    return 0;
}