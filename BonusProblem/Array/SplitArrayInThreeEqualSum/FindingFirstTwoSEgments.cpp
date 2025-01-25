#include<bits/stdc++.h>
using namespace std;

vector<int> findSplit(vector<int> &arr){
    vector<int> res;
    int total = 0;
    for(int ele : arr){
        total += ele;
    }

    if(total % 3 != 0){
        res = {-1, -1};
        return res;
    }

    int currSum = 0;
    
    for(int i=0;i<arr.size();i++){
        currSum += arr[i];
        if(currSum == total/3){
            currSum = 0;
            res.push_back(i);
            if(res.size() == 2 && i < arr.size()-1){
                return res;
            }
        }
    }
    res = {-1, -1};
    return res;
}

int main(){
    vector<int> arr = {1, 3, 4, 0, 4};
    vector<int> res = findSplit(arr);

    cout << res[0] << " " << res[1];

    return 0;
}