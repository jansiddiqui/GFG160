#include<bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> &arr, int target){
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];
        if (s.find(complement) != s.end())
            return true;

        s.insert(arr[i]);
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