#include<bits/stdc++.h>
using namespace std;

int kthMissing(vector<int>& arr, int k){
    unordered_set<int> s(arr.begin(), arr.end());
    int count = 0, curr = 0;

    while (count < k){
        curr++;

        if(s.find(curr) == s.end()){
            count++;
        }
    }
    return curr;
}
int main(){
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}