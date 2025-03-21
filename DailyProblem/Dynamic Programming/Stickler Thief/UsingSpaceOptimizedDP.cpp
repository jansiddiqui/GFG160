#include<bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    int secondLast = 0, last = arr[0];

    int res;
    for(int i=1;i<n;i++){
        res = max(arr[i] + secondLast, last);
        secondLast = last;
        last = res;
    }
    return res;
}

int main(){
    vector<int> arr = {6, 5, 5, 7, 4};
    cout<<findMaxSum(arr);
    return 0;
}