#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target){
    int cnt = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i] + arr[j] < target){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
    int target = 7;
    cout<<countPairs(arr, target);
    return 0;
}