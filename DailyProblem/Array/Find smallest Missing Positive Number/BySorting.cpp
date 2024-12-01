#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr){
    sort(arr.begin(), arr.end());

    int res = 1;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] == res){
            res++;
        }
        else if(arr[i]>res){
            break;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout<<missingNumber(arr);
    return 0;
}