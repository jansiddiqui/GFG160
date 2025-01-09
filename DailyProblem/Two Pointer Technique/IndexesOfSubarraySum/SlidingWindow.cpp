#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int>& arr, int target){
    int s= 0, e=0;
    vector<int> res;

    int curr = 0;

    for(int i = 0; i<arr.size(); i++){
        curr += arr[i];
        if(curr >= target){
            e = i;
            while(curr > target && s < e){
                curr -= arr[s];
                ++s;
            }
            if(curr == target){
                res.push_back(s + 1);
                res.push_back(e + 1);
                return res;
            }
        }
    }
    return {-1};
}

int main(){
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int> res = subarraySum(arr, target);
    for(int ele : res){
        cout<<ele<<" ";
    }
    return 0;
}