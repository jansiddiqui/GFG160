#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr){
    int n = arr.size();

    for(int i=0; i<n/2; i++){
        swap(arr[i], arr[n-i-1]);
    }
}

int main(){
    vector<int> arr={1,4,3, 5,6,7,8};
    reverseArray(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}