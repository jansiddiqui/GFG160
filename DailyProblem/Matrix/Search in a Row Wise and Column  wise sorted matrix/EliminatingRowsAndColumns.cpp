#include<bits/stdc++.h>
using namespace std;

bool matSearch(vector<vector<int>> &mat, int x){
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m-1;

    while(i<n && j >=0){
        if(x > mat[i][j]){
            i++;
        }
        else if(x < mat[i][j]){
            j--;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat = {{3, 20, 24},
    {12, 24, 28},
    {15, 25, 36} };
    int x = 24;
    if(matSearch(mat, x)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}