#include<bits/stdc++.h>
using namespace std;

int equiPoint(vector<int>& arr){
    int prefSum = 0, total = 0;

    for(int ele : arr){
        total += ele;
    }

    for(int pivot = 0; pivot < arr.size(); pivot++){
        int suffSum = total - prefSum - arr[pivot];
        if(prefSum == suffSum){
            return pivot;
        }
        prefSum += arr[pivot];
    }
    return  -1;
}
int main(){
    vector<int> arr = {1, 7, 3, 6, 5, 6};
    cout<<equiPoint(arr);
    return 0;
}