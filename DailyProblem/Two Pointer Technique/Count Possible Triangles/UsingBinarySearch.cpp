#include<bits/stdc++.h>
using namespace std;

int countTriangles(vector<int> &arr){
    int res = 0;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j<arr.size(); j++){
            int k = lower_bound(arr.begin() + j + 1, arr.end(), arr[i] + arr[j]) - arr.begin();
            int cnt = k - j - 1;
            res += cnt;
        }
    }
    return res;
}
int main(){
    vector<int> arr = {4, 6, 3, 7};
    cout << countTriangles(arr);
    return 0;
}