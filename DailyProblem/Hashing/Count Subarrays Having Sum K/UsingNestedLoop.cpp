#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& arr, int k){
    int res = 0;

    for(int s=0;s<arr.size();s++){
        int sum = 0;
        for(int e=s;e<arr.size();e++){
            sum += arr[e];
            if(sum == k){
                res++;
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << countSubarrays(arr, k);
    return 0;
}