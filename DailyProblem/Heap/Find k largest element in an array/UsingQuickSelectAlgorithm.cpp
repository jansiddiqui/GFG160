#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[right];
    int i = left;

    for(int j = left; j < right; j++){
        if(arr[j] >= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

void quickSelect(vector<int> &arr, int left, int right, int k){
    if(left <= right){
        int pivotIdx = partition(arr, left, right);
        int leftCnt = pivotIdx - left + 1;
        if(leftCnt == k){
            return;
        }
        if(leftCnt>k){
            quickSelect(arr, left, pivotIdx -1, k);
        }
        else{
            quickSelect(arr, pivotIdx + 1, right, k - leftCnt);
        }
    }
}
vector<int> kLargest(vector<int> &arr, int k){
    int n = arr.size();
    quickSelect(arr, 0, n-1, k);

    vector<int> res(arr.begin(), arr.begin()+ k);

    sort(res.begin(), res.end(), greater<int>());
    return res;
}

int main(){
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    vector<int> res = kLargest(arr, k);

    for(int ele : res){
        cout << ele << " ";
    }

    return 0;
}