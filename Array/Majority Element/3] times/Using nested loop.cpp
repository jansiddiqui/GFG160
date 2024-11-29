#include<bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int> &arr){
    int n = arr.size();
    vector<int>res;

    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = i; j<n; j++){
            if(arr[j]==arr[i]){
                count +=1;
            }
        }
    }
    if(count > (n/3)){
        if(res.size()==0 || arr[i] != res[0]){
            res.push_back(arr[i]);
        }
    }

    if(res.size() == 2){
        if(res[0] > res[1]){
            swap(res[0], res[1]);
        }
        break;
    }
    return res;
}

int main(){
    vector<int> arr = {2, 3, 2, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for(int ele : res){
        cout<<ele<<" ";
    }
    return 0;
}