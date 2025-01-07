#include<bits/stdc++.h>
using namespace std;

vector<int> sumClosest(vcetor<int> &arr, int target){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> res;

    int minDiff = INT_MAX;
    int left = 0, right = n-1;
    while(left < right){
        int currSum = arr[left] + arr[right];
        if(abs(target - currSum) < minDiff){
            minDiff = abs(target - currSum);
            res = {arr[left], arr[right]};
        }
        if(currSum < target){
            left++;
        }
        else if(currSum > target){
            right--;
        }
        else{
            return res;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    vector<int> res = sumClosest(arr, target);
    if(res.size() > 0){
        cout << res[0] << " "<<res[1];
    }
    return 0;
}