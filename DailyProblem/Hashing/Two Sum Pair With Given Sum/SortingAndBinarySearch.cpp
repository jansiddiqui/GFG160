#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &arr, int left, int right, int target){
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == target){
            return true;
        }
        if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}
bool twoSum(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());

    for(int i = 0; arr.size(); i++){
        int complement = target - arr[i];
        if(binarySearch(arr, i + 1, arr.size() - 1, complement)){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> arr = {0, 2, 3, 7, -1};
    int target = 6;

    if(twoSum(arr, target)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}