#include<bits/stdc++.h>
using namespace std;

void rotateArr(vector<int>& arr, int d){
    int n = arr.size();
    d %= n;

    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main(){
    vector<int> arr = {2, 3, 4,5 ,6, 7};
    int d=2;

    rotateArr(arr,d);

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}