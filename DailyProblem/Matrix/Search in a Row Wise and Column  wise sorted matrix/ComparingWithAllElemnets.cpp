#include<bits/stdc++.h>
using namespace std;

bool matSearch(vector<vector<int>> &mat, int x){
    int n = mat.size(), m = mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == x){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{3, 30, 38},
                              {20, 52, 54},
                              {35, 60, 69}};
    int x = 35;

    if(matSearch(mat, x)){
        cout << "Element is present";
    }
    else{
        cout<<"Element is not present";
    }
    return 0;
}