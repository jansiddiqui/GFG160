#include<bits/stdc++.h>
using namespace std;

int FD(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        if(arr[abs(arr[i])]<0){
            return abs(arr[i]);
        }
        arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,2,3,4,5};
    cout<<FD(arr);
    return 0;
}