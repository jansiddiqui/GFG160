#include<bits/stdc++.h>
using namespace std;

int maxValRec(vector<int>& arr, int i, int j){
    if(i>j) return 0;
    if(i == j) return arr[i];

    int pick = arr[j] + maxValRec(arr, i, j-2);
    int notPick = maxValRec(arr, i, j-1);

    return max(pick, notPick);
}
int maxValue(vector<int>& arr){
    int n = arr.size();
    int ans = 0;
    ans = max(ans, maxValRec(arr, 0, n-2));
    ans = max(ans, maxValRec(arr, 1, n-1));
    return ans;
}

int main(){
    vector<int> arr = {2,2,3,1,2};
    cout << maxValue(arr);
    return 0;
}