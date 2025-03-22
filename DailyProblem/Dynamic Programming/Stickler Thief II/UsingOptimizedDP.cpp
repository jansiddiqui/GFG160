#include<bits/stdc++.h>
using namespace std;

int maxValTab(int x, int y, vector<int> &arr){
    int n = arr.size();
    int prev2 = arr[x];
    int prev1 = max(arr[x], arr[x+1]);

    for(int j=x+2; j<=y;j++){
        int take = arr[j] + prev2;
        int notake = prev1;

        int curr = max(take, notake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maxValue(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    int ans = 0;
    ans = max(ans, maxValTab(0, n-2, arr));
    ans = max(ans, maxValTab(1, n-1, arr));
    return ans;
}
int main(){
    vector<int> arr = {2,2,3,1,2};
    cout<<maxValue(arr);
    return 0;
}