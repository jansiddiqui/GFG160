#include<bits/stdc++.h>
using namespace std;

int FD(vector<int> &arr){
    sort(arr.begin(), arr.end());
    for(int i=0;i<arr.size();i++){
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {2,2,3,4,5};
    cout<<FD(arr);
    return 0;
}