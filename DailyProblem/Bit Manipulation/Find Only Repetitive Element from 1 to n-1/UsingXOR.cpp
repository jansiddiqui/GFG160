#include<bits/stdc++.h>
using namespace std;

int FD(vector<int> &arr){
    int n = arr.size();
    int res = 0;
    for(int i=0;i<n-1;i++){
        res = res ^ (i+1) ^ arr[i];
    }
    res = res ^ arr[n-1];
    return res;
}
int main() {
    vector<int> arr  = {1,2,3,3,4,5};
    cout<<FD(arr);
    return 0;
}