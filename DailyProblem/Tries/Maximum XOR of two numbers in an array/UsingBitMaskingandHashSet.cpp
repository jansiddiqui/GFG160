#include<bits/stdc++.h>
using namespace std;

int maxXOR(vector<int> &arr){
    int res=0, mask = 0;
    unordered_set<int> s;
    for(int i=30;i>=0;i--){
        mask |= (1 << i);
        for(auto value:arr){
            s.insert(value & mask);
        }
        int cur = res | (1 << i);
        for(int prefix : s){
            if(s.count(cur ^ prefix)){
                res = cur;
                break;
            }
        }
        s.clear();
    }
    return res;
}
int main(){
    vector<int> arr = {26, 100, 25, 13, 4, 14};
    cout<<maxXOR(arr);
    return 0;
}