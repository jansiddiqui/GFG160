#include<bits/stdc++.h>
using namespace std;

int FU(vector<int> &arr){
    int n = arr.size();
    
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }
        if(cnt == 1){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    vector<int>arr = {2,3,5,4,5,3,4};
    cout<<FU(arr);
    return 0;
}