#include<bits/stdc++.h>
using namespace std;

vector<int> sumClosest(vector<int> &arr, int target){
    int n = arr.size();

    vector<int> res;
    int minDiff = INT_MAX;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int currSum = arr[i] + arr[j];
            int currDiff = abs(currSum - target);

            if(currDiff < minDiff){
                minDiff = currDiff;
                res = {min(arr[i], arr[j]), max(arr[i], arr[j])};
            }
            else if(currDiff == minDiff && (res[1] - res[0]) < abs(arr[i] - arr[j])){
                res = {min(arr[i], arr[j]), max(arr[i], arr[j])};
            }
        }
    }
    return res;
}

int main(){
    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    vector<int> res = sumClosest(arr, target);
    if(res.size() > 0){
        cout << res[0] << " " << res[1];
    }
    return 0;
}