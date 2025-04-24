#include<bits/stdc++.h>
using namespace std;

int getSingle(vector<int> &arr){
    int res = 0, x, sum;
    for(int i=0;i<32;i++){
        sum = 0;
        x = (1 << i);
        for(int j=0;j<arr.size();j++){
            if(arr[j] & x){
                sum++;
            }
        }
        if((sum%3) != 0){
            res |= x;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {1,10,1,1};
    cout<<getSingle(arr);
    return 0;
}