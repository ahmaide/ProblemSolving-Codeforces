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

void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int toNum(char c){
    return c-48;
}

char toChar(int i, int j){
    char c = (i+ (j*10) + 96);
    /*if(c<=96)
        c+=22;*/
    return c;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    int n;
    cin >> n;
    string arr[n];
    for(int i=0 ; i<n ; i++){
        arr[i]="";
        int s;
        cin >>s;
        string wo;
        cin >> wo;
        for(int j=0; j<s ; j++){
            if(j<s-3){
                if(wo[j+2]!='0' || (wo[j+2]=='0' && wo[j+3]=='0')){
                    char c1 = wo[j];
                    arr[i] = arr[i] + toChar(toNum(c1),0);
                }
                else{
                    arr[i] = arr[i] + toChar(toNum(wo[j+1]), toNum(wo[j]));
                    j+=2;
                }
            }
            else{
                if(wo[s-1]=='0'){
                    arr[i] = arr[i] + toChar(toNum(wo[j+1]), toNum(wo[j]));
                    j+=2;
                }
                else
                    arr[i] = arr[i] + toChar(toNum(wo[j]),0);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}