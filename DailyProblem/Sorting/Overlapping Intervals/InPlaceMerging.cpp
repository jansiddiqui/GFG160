#include<bits/stdc++.h>
using namespace std;

int mergeOverlap(vector<vector<int>>& arr){
    sort(arr.begin(), arr.end());

    int resIdx = 0;

    for(int i=1;i<arr.size();i++){
        if(arr[resIdx][1] >= arr[i][0]){
            arr[resIdx][1] = max(arr[resIdx][1], arr[i][1]);
        }
        else{
            resIdx++;
            arr[resIdx] = arr[i];
        }
    }
    return (resIdx + 1);
}

int main(){
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    int  newSize = mergeOverlap(arr);

    for(int i=0;i<newSize;i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
    }
    return 0;
}