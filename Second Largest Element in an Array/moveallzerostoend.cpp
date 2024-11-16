#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void pushZerosToEnd(vector<int>& arr){
        int n = arr.size();
        int nonZeroIndex = 0;

        for(int i = 0; i<n; i++){
            if(arr[i] != 0){
                arr[nonZeroIndex++] = arr[i];
            }
        }

        while(nonZeroIndex < n){
            arr[nonZeroIndex++] = 0;
        }
    }
};

int main(){
    vector<int> arr = {0, 1, 0, 3, 12};
    Solution obj;
    obj.pushZerosToEnd(arr);
    cout << "Array after pushing zeros to the end: ";
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}