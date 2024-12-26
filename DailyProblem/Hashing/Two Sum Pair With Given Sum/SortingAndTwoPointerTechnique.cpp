#include<bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    while (left < right){
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++; 
        else
            right--; 
    }
    return false;
}

int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}