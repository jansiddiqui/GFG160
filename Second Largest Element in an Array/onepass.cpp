#include<bits/stdc++.h>
using namespace std;

int getsecondlargest(vector<int> &arr){
    int n = arr.size();

    int largest = INT_MIN, secondlargest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            secondlargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondlargest){
            secondlargest = arr[i];
        }
    }
    return secondlargest;
}
int main(){
    vector<int> arr = {-23, -27, -25, -22, -26, -24, -28};
    cout<<getsecondlargest(arr);
    return 0;
}