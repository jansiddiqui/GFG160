#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr){
    int lo=0, hi = arr.size() - 1;
    while(lo < hi){
        if(arr[lo] < arr[hi]){
            return arr[lo];
        }
        int mid = (lo + hi) / 2;
        if(arr[mid] > arr[hi]){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }
    return arr[lo];
}

int main(){
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << findMin(arr)<<endl;
    return 0;
}