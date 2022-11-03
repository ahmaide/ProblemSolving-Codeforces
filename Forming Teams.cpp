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

pair<int, int> DFS(int checked[], vector<int> riv [], int bench, int o, bool first, int team){
    if(riv[o].size()==0 || (first== false && riv[o].size()==1)){
        checked[o]=team;
        return {bench, team};
    }
    else{
        if(riv[o].size()==1 && first == true){
            checked[o]=team;
            int t = (team%2) + 1;
            pair<int, int> r = DFS(checked, riv, bench, riv[o][0], false, t);
            bench = r.first;
            team = r.second;
            return {bench, team};
        }
        else if(riv[o].size()==2 && first==true){
            checked[o]=team;
            int t = (team%2) + 1;
            for(int i=0; i<2 ; i++){
                if(checked[riv[o][i]]==0){
                    pair<int, int>r= DFS(checked, riv, bench, riv[o][i], false, t);
                    bench=r.first;
                    team=r.second;
                }
            }
            return {bench, team};
        }
        else{
            if(checked[riv[o][0]]!=0 && checked[riv[o][0]]==checked[riv[o][1]]){
                checked[o]=team;
                return {bench, team};
            }
            else if(checked[riv[o][0]]!=0 && checked[riv[o][1]]!=0 && checked[riv[o][0]]!=checked[riv[o][1]]){
                checked[o]=3;
                bench++;
                return{bench, team};
            }
            else{
                int m=0;
                if(checked[riv[o][0]]!=0)
                    m=1;
                checked[o]=team;
                int t = (team%2) + 1;
                pair<int, int>r= DFS(checked, riv, bench, riv[o][m], false, t);
                bench=r.first;
                team=r.second;
                return {bench, team};
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    int checked[n];
    std::fill_n (checked, n, 0);
    vector<int> riv [n];
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        riv[x].push_back(y);
        riv[y].push_back(x);
    }
    int bench=0;
    int team=1;
    for(int i=0 ; i<n ; i++){
        if(checked[i]==0){
            pair<int, int> p = DFS(checked,riv,bench, i, true, team );
            bench=p.first;
            team=p.second;
            team = (team%2)+1;
        }
    }
    if((n-bench)%2==1)
        bench++;
    cout << bench;
    return 0;
}