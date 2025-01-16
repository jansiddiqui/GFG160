#include<bits/stdc++.h>
using namespace std;

int maxlen(vector<int>& arr){
    int res = 0;

    for(int s=0;s<arr.size();s++){
        int sum = 0;
        for(int e=s;e<arr.size();e++){
            sum += (arr[e] == 0) ? -1 : 1;
            if(sum == 0){
                res = max(res, e-s+1);
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {1, 0, 1, 0, 0, 1};
    cout<<maxlen(arr);
    return 0;
}