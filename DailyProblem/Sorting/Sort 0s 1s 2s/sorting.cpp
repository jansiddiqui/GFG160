#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr){
    int n = arr.size();
    int c0 = 0, c1 = 0, c2 = 0;

    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            c0++;
        }
        else if(arr[i] == 1){
            c1++;
        }
        else{
            c2++;
        }
    }

    int idx = 0;

    for(int i=0;i<c0;i++){
        arr[idx++] = 0;
    }

    for(int i=0;i<c1;i++){
        arr[idx++] = 1;
    }

    for(int i=0;i<c2;i++){
        arr[idx++] = 2;
    }
}

int main(){
    vector<int> arr = {0, 1, 2, 1, 2, 1, 0};
    sort012(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}