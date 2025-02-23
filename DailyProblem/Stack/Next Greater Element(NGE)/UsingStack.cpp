#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargEle(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> stk;

    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && stk.top() <= arr[i]){
            stk.pop();
        }

        if(!stk.empty()){
            res[i] = stk.top();
        }
        stk.push(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> res = nextLargEle(arr);

    for(int x : res){
        cout<<x<<" ";
    }
    return 0;
}