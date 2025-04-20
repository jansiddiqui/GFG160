#include<bits/stdc++.h>
using namespace std;

int FD(vector<int> &arr){
    unordered_set<int> s;
    for(int x : arr){
        if(s.find(x) != s.end()){
            return x;
        }
        s.insert(x);
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,2,3,4,5};
    cout<<FD(arr);
    return 0;
}