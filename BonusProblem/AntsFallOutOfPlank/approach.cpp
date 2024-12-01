#include<bits/stdc++.h>
using namespace std;

int getLastMoment(int n, vector<int> &left, vector<int> &right){
    int res = 0;

    for(int i=0;i<left.size();i++){
        res = max(res, left[i]);
    }

    for(int i = 0; i<right.size();i++){
        res = max(res, n - right[i]);
    }
    return res;
}

int main(){
    int n = 5;
    vector<int> left = {2};
    vector<int> right = {0, 1, 3};
    cout<<getLastMoment(n, left, right);
    return 0;
}