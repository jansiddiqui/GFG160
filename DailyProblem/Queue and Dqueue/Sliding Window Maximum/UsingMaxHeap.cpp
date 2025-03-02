#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarray(const vector<int> & arr, int k){
    int n = arr.size();
    vector<int> res;
    priority_queue<pair<int, int>>heap;
    for(int i=0;i<k;i++){
        heap.push({arr[i], i});
    }

    res.push_back(heap.top().first);

    for(int i = k;i<arr.size();i++){
        heap.push({arr[i], i});
        while(heap.top().second <= i-k){
            heap.pop();
        }
        res.push_back(heap.top().first);
    }
    return res;
}
int main(){
    vector<int> arr = {1,2,3,1,4,5,2,3,6};
    int k=3;
    vector<int>res = maxOfSubarray(arr, k);
    for(int maxVAl : res){
        cout << maxVAl<<" ";
    }
    return 0;
}