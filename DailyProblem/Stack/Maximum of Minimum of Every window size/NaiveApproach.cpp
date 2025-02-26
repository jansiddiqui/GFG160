#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfMins(vector<int>& arr){
    int n = arr.size();
    vector<int> res(n, 0);

    for(int k=1; k<=n; k++){
        int maxOfMin = INT_MIN;

        for(int i=0;i<=n-k;i++){
            int minVal = arr[i];
            for(int j =1;j<k;j++){
                if(arr[i+j]<minVal){
                    minVal = arr[i+j];
                }
            }
            if(minVal > maxOfMin){
                maxOfMin = minVal;
            }
        }
        res[k-1] = maxOfMin;
    }
    return res;
}

int main(){
    vector<int> arr = {10, 20 ,30, 50, 10, 70, 30};
    vector<int> res = maxOfMins(arr);
    for(int x : res)
        cout << x << " ";
    return 0;
}