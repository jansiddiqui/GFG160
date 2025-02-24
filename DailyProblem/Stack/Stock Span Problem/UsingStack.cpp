#include<bits/stdc++.h>
using namespace std;

vector<int> calSpan(vector<int>& arr){
    int n = arr.size();
    vector<int> span(n);
    stack<int> s;

    for(int i=0; i<n;i++){
        while(!s.empty() && arr[s.top()]<=arr[i]){
            s.pop();
        }

        if(s.empty()){
            span[i]=(i+1);
        }
        else{
            span[i] = (i - s.top());
        }
        s.push(i);
    }
    return span;
}
int main(){
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calSpan(arr);
    for(int x : span){
        cout << x << " ";
    }
    return 0;
}