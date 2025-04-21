#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &arr){
    int n = arr.size() + 1;

    for(int i=1;i<=n;i++){
        bool found = false;
        for(int j=0;j<n-1;j++){
            if(arr[j] == i){
                found = true;
                break;
            }
        }
        if(!found){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5,7};
    cout<<missingNum(arr);
    return 0;
}