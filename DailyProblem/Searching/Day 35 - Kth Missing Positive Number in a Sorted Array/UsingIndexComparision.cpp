#include<bits/stdc++.h>
using namespace std;

int kthMissing(vector<int> &arr, int k){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]>(k + i)){
            return (k + i);
        }
    }
    return k + n;
}
int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout<<kthMissing(arr, k);
    return 0;
}