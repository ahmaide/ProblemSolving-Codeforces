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
    int sum=0;
    cin >> n;
    int arr[n];
    for(int i=0;i<n; i++)
        cin >> arr[i];
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            sum++;
        else if(i<n-1 && (arr[i]==1 || arr[i]==2) && arr[i]==arr[i+1] ){
            sum++;
            i+=1;
        }
        else if(i<n-2 && (arr[i]==1 || arr[i]==2) && arr[i+1]==3){
            int m=arr[i];
            i++;
            int cou=0;
            while(arr[i]==3 && i<n){
                i++;
                cou++;
            }
            if(i<n){
                if(arr[i]==0)
                    sum++;
                else{
                    if((arr[i]!=m && cou%2==1) || (arr[i]==m && cou%2==0))
                        sum++;
                    else
                        i--;
                }
            }
        }
    }
    cout << sum;
    return 0;
}