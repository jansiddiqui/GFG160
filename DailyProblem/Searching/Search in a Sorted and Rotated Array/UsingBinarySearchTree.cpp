#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &arr, int lo, int hi, int x){
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
int findPivot(vector<int> &arr, int lo, int hi){
    while(lo < hi){
        if(arr[lo] <= arr[hi]){
            return lo;
        }
        int mid = (lo + hi) / 2;
        if(arr[mid] > arr[hi]){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }
    return lo;
}

int search(vector<int> &arr, int key){
    int n = arr.size();
    int pivot = findPivot(arr, 0, n - 1);

    if(arr[pivot] == key){
        return pivot;
    }
    if(pivot == 0){
        return BinarySearch(arr, 0, n - 1, key);
    }
    if(arr[0] <= key){
        return BinarySearch(arr, 0, pivot - 1, key);
    }
    return BinarySearch(arr, pivot + 1, n-1, key);
}

int main(){
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    cout<<search(arr, key);
    return 0;
}