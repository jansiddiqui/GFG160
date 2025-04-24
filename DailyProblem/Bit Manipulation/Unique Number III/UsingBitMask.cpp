#include<bits/stdc++.h>
using namespace std;

int getSingle(vector<int>& arr){
    int ones = 0, twos=0, mask;
    for(int num : arr){
        twos |= ones & num;
        ones ^= num;
        mask = ~(ones & twos);
        ones &= mask;
        twos &= mask;
    }
    return ones;
}
int main(){
    vector<int> arr = {1,10,1,1};
    cout<<getSingle(arr);
    return 0;
}