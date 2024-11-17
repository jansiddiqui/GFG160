#include<bits/stdc++.h>
using namespace std;

void pushzerostoend(vector<int> &arr){
    int n = arr.size();
    vector<int> temp(n);

    int j=0;

    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            temp[j++]=arr[i];
        }
    }

    while(j<n){
        temp[j++]=0;
    }

    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
int main(){
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushzerostoend(arr);

    for(int num : arr){
        cout<<num<<" ";
    }

    return 0;
}