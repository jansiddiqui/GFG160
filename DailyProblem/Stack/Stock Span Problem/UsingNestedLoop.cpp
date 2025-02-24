#include<bits/stdc++.h>
using namespace std;

vector<int> calSpan(vector<int>& arr){
    int n = arr.size();
    vector<int> span(n, 1);
    for(int i=0;i<n;i++){
        for(int j=i-1;(j>=0)&&(arr[i]>=arr[j]);j--){
            span[i]++;
        }
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