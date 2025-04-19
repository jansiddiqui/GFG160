#include<bits/stdc++.h>
using namespace std;

int maxXOR(vector<int> &arr){
    int res = 0;
    int fir = 0, sec = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if((arr[i]^arr[j]) >res){
                res = max(res, arr[i]^arr[j]);
                fir = arr[i], sec = arr[j];
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {26, 100, 25, 13, 4, 14};
    cout<<maxXOR(arr);
    return 0;
}