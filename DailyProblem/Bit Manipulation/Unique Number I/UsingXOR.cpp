#include<bits/stdc++.h>
using namespace std;

int findUnique(vector<int> &arr){
    int n = arr.size();
    int res = 0;
    
    for(int i=0;i<n;i++){
        res = res ^ arr[i];
    }
    return res;
}
int main(){
    vector<int> arr = {2,3,5,4,5,3,4};
    cout<<findUnique(arr);
    return 0;
}