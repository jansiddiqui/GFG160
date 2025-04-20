#include<bits/stdc++.h>
#include<numeric>
using namespace std;

int findD(vector<int> &arr){
    long long n = arr.size();
    // Find the sum of elements in the array
    // and subtract the sum of the first n-1 
    // natural numbers to find the repeating element.
    long long sum = accumulate(arr.begin(), arr.end(), 0);
    int duplicate = sum - ((n-1) * n/2);
    return duplicate;
}
int main(){
    vector<int> arr = {1,2,2,4,5,3};
    cout<<findD(arr); 
    return 0;
}