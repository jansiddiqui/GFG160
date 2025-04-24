#include<bits/stdc++.h>
using namespace std;

int getSingle(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }
        if(cnt == 1){
            return arr[i];
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,10,1,1};
    cout<<getSingle(arr);
    return 0;
}