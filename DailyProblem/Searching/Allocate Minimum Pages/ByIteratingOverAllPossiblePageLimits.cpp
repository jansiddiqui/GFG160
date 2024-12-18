#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr, int k, int pageLimit) {
    
    int cnt = 1;
    int pageSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        
        if(pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        }
        else {
            pageSum += arr[i];
        }
    }
    
    return (cnt <= k);
}

int findPages(vector<int> &arr, int k) {
    
    if(k > arr.size())
        return -1;
        
    int minPageLimit = *max_element(arr.begin(), arr.end());
    int maxPageLimit = accumulate(arr.begin(), arr.end(), 0);
    
    for(int i = minPageLimit; i <= maxPageLimit; i++) {
        
        if(check(arr, k, i))
            return i;
    }
    
    return -1;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(arr, k);
    return 0;
}
