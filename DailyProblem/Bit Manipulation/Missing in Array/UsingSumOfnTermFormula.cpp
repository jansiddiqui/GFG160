#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &arr){
    int n = arr.size()+1;

    int sum = 0;

    for(int i=0;i<n-1;i++){
        sum += arr[i];
    }
    long long expSum = (n*1LL*(n+1))/2;

    return expSum - sum;
}
int main(){
    vector<int> arr = {1,2,3,4,6,7};
    cout<<missingNum(arr);
    return 0;
}