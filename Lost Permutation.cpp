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
    for(int i=0; i <n; i++){
        int m,s;
        cin >> m >> s;
        vector<int>v;
        int sum=0;
        int max=0;
        for(int j=0; j<m ; j++){
            int w;
            cin >> w;
            v.push_back(w);
            if(w>max)
                max=w;
        }
        int j=1;
        for(j=1; sum<s ; j++){
            if(find(v.begin(), v.end(), j) == v.end()){
                v.push_back(j);
                sum+=j;
            }
        }
        if(sum==s){
            for(j=j; find(v.begin(), v.end(), j) != v.end() && j<max; j++);
        }
        if(sum==s && j>=max)
            arr[i]=true;
        else
            arr[i]=false;
    }
    for(int i=0; i<n; i++){
        if(arr[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}