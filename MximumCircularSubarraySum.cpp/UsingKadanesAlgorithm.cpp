#include<bits/stdc++.h>
using namespace std;

int cirSubArrSum(vector<int> &arr){
    int totalSum = 0;
    int currMaxSum = 0, currMinSum = 0;
    int maxSum = arr[0], minSum = arr[0];

    for(int i=0;i<arr.size();i++){
        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum);

        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum);

        totalSum = totalSum + arr[i];
    }

    int normalSum = maxSum;
    int circularSum = totalSum - minSum;

    if(minSum == totalSum){
        return normalSum;
    }
    return max(normalSum, circularSum);
}
int main(){
    vector<int> arr = {-1, 40, -14, 7, 6, 5, -4, -1};
    cout<<cirSubArrSum(arr);
}