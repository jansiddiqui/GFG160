#include<bits/stdc++.h>
using namespace std;

int invCount(vector <int> &arr){
    int n = arr.size();
    int invTime = 0;

    for(int i = 0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                invTime++;
            }
        }
    }
    return invTime;
}
int main(){
    vector <int> arr = {4, 3, 2, 1};
    cout << invCount(arr)<<endl;
    return 0;
}