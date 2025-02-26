#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfMins(vector<int>& arr){
    int n = arr.size();
    vector<int> res(n, 0);
    stack<int> s;

    vector<int> len(n, 0);
    for(int i=0; i<n; i++){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            int top = s.top();
            s.pop();
            int windowSize = s.empty() ? i : i - s.top() - 1;
            len[top] = windowSize;
        }
        s.push(i);
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        int windowSize = s.empty() ? n : n - s.top() - 1;
        len[top] = windowSize;
    }
    for(int i=0;i<n;i++){
        int windowSize = len[i] - 1;
        res[windowSize] = max(res[windowSize], arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        res[i] = max(res[i], res[i+1]);
    }
    return res;
}

int main(){
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> res = maxOfMins(arr);
    for(int x : res){
        cout << x << " ";
    }
    return 0;
}