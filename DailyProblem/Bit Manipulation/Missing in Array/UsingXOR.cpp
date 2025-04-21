#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &arr){
    int n = arr.size()+1;
    int xor1 = 0, xor2 = 0;

    for(int i=0;i<n-1;i++){
        xor2 ^= arr[i];
    }

    for(int i=1;i<=n;i++){
        xor1 ^= i;
    }

    return xor1 ^ xor2;
}
int main(){
    vector<int> arr = {1,2,3,4,6,7};
    cout<<missingNum(arr);
    return 0;
}