#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int l, int r){
    if(l>=r){
        return;
    }

    swap(arr[l], arr[r]);

    reverseArray(arr, l + 1, r - 1);
}

void reverseArray(vector<int> &arr){
    int n=arr.size();
    reverseArray(arr, 0, n-1);
}

int main(){
    vector<int> arr = {1,4,3,2,6,5};
    reverseArray(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}