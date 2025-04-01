#include<bits/stdc++.h>
using namespace std;

int AS(vector<int> &s, vector<int> &f){
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    for(int i=0; i<s.size();i++){
        p.push(make_pair(f[i], s[i]));
    }
    int finishtime = -1;
    while(!p.empty()){
        pair<int, int> activity = p.top();
        p.pop();
        if(activity.second > finishtime){
            finishtime = activity.first;
            ans++;
        }
    }
    return ans;
}
int main(){
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};
    cout << AS(s, f);
    return 0;
}