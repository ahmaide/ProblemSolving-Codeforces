#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

char color(int num){
    int p = num%7;
    switch(p){
        case 0: return 'R';
            break;
        case 1: return 'O';
            break;
        case 2: return 'Y';
            break;
        case 3: return 'G';
            break;
        case 4: return 'B';
            break;
        case 5: return 'I';
            break;
        default: return 'V';
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    int n;
    cin >> n;
    char arr[n];
    for(int i=0; i<7 && i<n; i++){
        arr[i] = color(i);
    }
    if(n<=10 && n>7){
        arr[7]='G';
        if(n>8){
            arr[8]='B';
            if(n>9)
                arr[9]='I';
        }
    }
    else if(n>10){
        for(int i=7; i<n-3;i++)
            arr[i]=color((i+1)%4);
        arr[n-3]='B';
        arr[n-2]='I';
        arr[n-1]='V';
    }
    for(int i=0 ; i<n ; i++)
        cout << arr[i];
    return 0;
}