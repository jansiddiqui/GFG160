#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(vector<int> &arr, int k){
    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> res(arr.begin(), arr.begin() + k);
    return res;
}

int main(){
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    vector<int> res = kLargest(arr, k);
    for(int ele:res){
        cout<<ele<<" ";
    }
    return 0;
}