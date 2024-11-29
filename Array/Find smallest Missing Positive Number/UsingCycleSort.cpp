#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        while(arr[i]>=1 && arr[i]<=n && arr[i] != arr[arr[i]-1]){
            swap(arr[i], arr[arr[i]-1]);
        }
    }
    for(int i=1; i<=n; i++){
        if(i != arr[i-1]){
            return i;
        }
    }
    return n+1;
}
int main(){
    vector<int> arr = {1, 2, 4, 6, 3};
    cout<<missingNumber(arr);
    return 0;
}