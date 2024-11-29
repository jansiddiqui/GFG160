#include<bits/stdc++.h>
using namespace std;

int cirSubArrSum(vector<int> &arr){
    int n = arr.size();
    int sufSum = arr[n-1];

    vector<int> maxSuf(n+1, 0);
    maxSuf[n-1] = arr[n-1];

    for(int i = n - 2; i >= 0; i--){
        sufSum = sufSum + arr[i];
        maxSuf[i] = max(maxSuf[i + 1], sufSum);
    }

    int circularSum = arr[0];
    int normalSum = arr[0];
    int currSum = 0;
    int prefix = 0;

    for(int i=0;i<n;i++){
        currSum = max(currSum + arr[i], arr[i]);
        normalSum = max(normalSum, currSum);

        prefix = prefix + arr[i];
        circularSum = max(circularSum, prefix+maxSuf[i+1]);
    }
    return max(circularSum, normalSum);
}
int main(){
    vector<int> arr = {10, -3, -4, 7, 6, 5, -4, -1};
    cout<<cirSubArrSum(arr);
}