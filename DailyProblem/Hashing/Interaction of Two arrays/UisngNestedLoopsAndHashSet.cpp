#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b){
    unordered_set<int> as(a.begin(), a.end());
    unordered_set<int> rs;
    vector<int> res;

    for(int i=0;i<b.size();i++){
        if(as.find(b[i]) != as.end() && rs.find(b[i]) == rs.end()){
            rs.insert(b[i]);
            res.push_back(b[i]);
        }
    }
    return res;
}
int main(){
    vector<int> a={1,2,3,2,1};
    vector<int> b={3,2,2,3,3,2};
    vector<int> res = intersection(a,b);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}