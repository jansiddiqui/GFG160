#include<bits/stdc++.h>
using namespace std;

void pushzerotoend(vector<int>& arr){
    int count = 0;

    for(int i=0;i<arr.size(); i++){
        if(arr[i]!=0){
            swap(arr[i], arr[count]);
            count++;
        }
    }
}
int main(){
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushzerotoend(arr);
    for(int num : arr){
        cout<<num<<" ";
    }
    return 0;
}