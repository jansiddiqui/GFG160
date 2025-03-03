#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubarray(vector<int>& arr, int x){
    int n = arr.size();
    int maxLen = 0;
    int beginning = 0;
    map<int, int> window;
    int start=0, end=0;
    for(; end<n; end++){
        window[arr[end]]++;

        auto minimum = window.begin()->first;
        auto maximum = window.rbegin()->first;
        if(maximum - minimum <= x){
            if(maxLen < end - start + 1){
                maxLen = end - start + 1;
                beginning = start;
            }
        }
        else{
            while(start < end){
                window[arr[start]]--;
                if(window[arr[start]] == 0){
                    window.erase(window.find(arr[start]));
                }

                start++;

                auto minimum = window.begin()->first;
                auto maximum = window.rbegin()->first;

                if(maximum - minimum <= x){
                    break;
                }
            }
        }
    }
    vector<int> res;
    for(int i=beginning;i<beginning+maxLen;i++){
        res.push_back(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {8, 4, 2, 6, 7};
    int x=4;
    vector<int> res = longestSubarray(arr, x);
    for(auto val : res){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}