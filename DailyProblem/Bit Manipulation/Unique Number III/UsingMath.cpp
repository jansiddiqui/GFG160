#include<bits/stdc++.h>
using namespace std;

int getSingle(vector<int> &arr){
    unordered_set<int> uniqueElement;
    int tSum = 0;
    for(int num : arr){
        tSum += num;
        uniqueElement.insert(num);   
    }
    int uniqueSum = 0;
    for(int num : uniqueElement){
        uniqueSum += num;
    }

    int res = (3 * uniqueSum - tSum) / 2;
    return res;
}
int main(){
    vector<int> arr = {1,10,1,1};
    cout<<getSingle(arr);
    return 0;
}