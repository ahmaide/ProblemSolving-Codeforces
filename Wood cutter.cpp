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
    pair<int, int> trees[n];
    int sum =2;
    int space=0;
    for(int i=0;i <n;i++){
        cin >> trees[i].first;
        cin >> trees[i].second;
    }
    if(n<2)
        sum=n;
    else
        space = trees[1].first - trees[0].first;
    for(int i=1; i<n-1 ;i++){
        if(space > trees[i].second){
            sum++;
            space = trees[i+1].first - trees[i].first;
        }
        else{
            if(trees[i+1].first-trees[i].first > trees[i].second){
                sum++;
                space = trees[i+1].first - trees[i].first - trees[i].second;
            }
            else
                space = trees[i+1].first - trees[i].first;
        }
    }
    cout << sum;
    return 0;
}