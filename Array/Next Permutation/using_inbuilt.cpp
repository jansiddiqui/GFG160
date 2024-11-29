#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    next_permutation(arr.begin(), arr.end());
    for(int num :  arr){
        cout<<num<<" ";
    }
    return 0;
}