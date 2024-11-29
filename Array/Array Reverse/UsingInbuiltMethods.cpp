#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr){
    reverse(arr.begin(), arr.end());
}

int main(){
    vector<int> arr = {1, 4, 3, 7, 9,3};
    reverseArray(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}