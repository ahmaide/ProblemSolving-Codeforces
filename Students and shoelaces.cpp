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
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> graph[n];
    for(int i=0 ; i<m ; i++){
        int w1, w2;
        cin >> w1 >> w2;
        w1--;
        w2--;
        graph[w1].push_back(w2);
        graph[w2].push_back(w1);
    }
    int sum=0;
    bool cont=false;
    vector<int>next[2];
    int z1=0;
    int z2=1;
    for(int i=0; i<n; i++){
        if(graph[i].size()==1)
            next[z1].push_back(i);
    }
    if(next[z1].size()>0)
        cont=true;
    while(cont){
        cont=false;
        for(int i=0; i<next[z1].size(); i++){
            int stu=next[z1][i];
            int other = graph[stu][0];
            graph[stu].pop_back();
            graph[other].erase(std::remove(graph[other].begin(), graph[other].end(), stu), graph[other].end());
            if(graph[other].size()==1) {
                next[z2].push_back(other);
                cont = true;
            }
        }
        z1=(z1+1)%2;
        z2=(z2+1)%2;
        sum+=1;
        next[z2].clear();
        bool jk=true;
        for(int i=0; i<next[z1].size() ; i++){
            if(graph[next[z1][i]].size()!=0)
                jk= false;
            else {
                next[z1].erase(std::remove(next[z1].begin(), next[z1].end(), next[z1][i]), next[z1].end());
                i--;
            }
        }
        if(jk)
            cont=false;
    }
    cout << sum;
    return 0;
}