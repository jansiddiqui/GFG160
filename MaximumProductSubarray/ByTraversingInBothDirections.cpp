#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &arr){
    int n = arr.size();
    int maxProd = INT_MIN;
    int leftToRight = 1;
    int rightToLeft = 1;

    for(int i=0;i<n;i++){
        if(leftToRight == 0){
            leftToRight = arr[i];
        }
        if(rightToLeft == 0){
            rightToLeft = 1;
        }
        leftToRight *= arr[i];
        int j=n-i-1;
        rightToLeft *= arr[j];
        maxProd = max({leftToRight, rightToLeft, maxProd});
    }
    return maxProd;
}

int main(){
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout<<maxProduct(arr);
    return 0;
}