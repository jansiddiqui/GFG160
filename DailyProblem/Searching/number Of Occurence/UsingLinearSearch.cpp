#include<bits/stdc++.h>
using namespace std;

int countfreq(vector<int> &arr, int target){
    int res = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == target){
            res++;
        }
    }
    return res;
}
int main(){
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int target = 2;
    cout<<countfreq(arr, target);
    return 0;
}