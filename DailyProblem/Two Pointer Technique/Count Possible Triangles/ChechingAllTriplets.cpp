#include<bits/stdc++.h>
using namespace std;

int countTriangles(vector<int>& arr){
    int res = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            for(int k = j + 1; k < arr.size(); k++){
                if(arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[k] + arr[j] > arr[i]){
                    res++;
                }
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {4, 6, 3, 7};
    cout<<countTriangles(arr);
    return 0;
}