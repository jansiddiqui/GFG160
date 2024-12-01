#include<bits/stdc++.h>
using namespace std;

int getsecondlargest(vector<int> &arr){
    int n = arr.size();

    int largest = INT_MIN, secondlargest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i] > secondlargest && arr[i] != largest){
            secondlargest = arr[i];
        }
    }
    return secondlargest;
}

int main(){
    vector<int> arr = {4, 5, 25, 21, 35, 22};

    cout<<getsecondlargest(arr);
}