#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &arr, int target){
    int n = arr.size();
    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
                cnt++;
            }
        }
    }
    return cnt;
}
int  main(){
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;
    cout<<countPairs(arr, target)<<endl;
    return 0;
}