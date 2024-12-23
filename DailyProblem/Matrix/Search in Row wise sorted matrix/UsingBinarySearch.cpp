#include<bits/stdc++.h>
using namespace std;

bool search(vector<int> &arr, int x){
    int lo = 0, hi = arr.size();
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(x == arr[mid]){
            return true;
        }
        if(x < arr[mid]){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return false;
}

bool searchRowMatrix(vector<vector<int>> &mat, int x){
    int n = mat.size(), m = mat[0].size();
    for(int i = 0;i < n; i++){
        if(search(mat[i], x)){
            return true;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> mat = {{3, 4, 9}, {2, 5, 6}, {9, 25, 27}};
    int x=9;
    if(searchRowMatrix(mat, x)){
        cout << "Element is present in the matrix";
    }
    else{
        cout << "Element is not present in the matrix";
    }
    return 0;
}