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
    int arr[n];
    for(int i=0; i<n ; i++){
        arr[i]=-1;
        int l,r,x, a, b;
        cin >> l >> r >> x >> a >> b;
        if(a==b)
            arr[i]=0;
        else{
            if(abs(a-b) >= x)
                arr[i]=1;
            else{
                if(a-l>=x){
                    if(b-l>=x)
                        arr[i]=2;
                    else{
                        if(r-b>=x)
                            arr[i]=3;
                    }
                }
                if(r-a>=x){
                    if(r-b>=x)
                        arr[i]=2;
                    else{
                        if(b-l>=x && arr[i]==-1)
                            arr[i]=3;
                    }
                }
            }
        }
    }
    for(int i=0 ; i<n ; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}