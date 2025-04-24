#include<bits/stdc++.h>
using namespace std;

int getSingle(vector<int> &arr){
    unordered_map<int, int> freq;

    for(int num : arr){
        freq[num]++;
    }
    for(auto it : freq){
        if(it.second == 1){
            return it.first;
        }
    }
    return 0;
}
int main(){
    vector<int> arr = {1,10,1,1};
    cout<<getSingle(arr);
    return 0;
}