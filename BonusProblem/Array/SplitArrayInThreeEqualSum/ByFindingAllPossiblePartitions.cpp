#include<bits/stdc++.h>
using namespace std;

int findSum(vector<int> &arr, int start, int end){
    int sum = 0;
    for(int i = start; i<=end; i++){
        sum += arr[i];
    }
    return sum;
}

vector<int> findSplit(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            int sum1 = findSum(arr, 0, i);
            int sum2 = findSum(arr, i + 1, j);
            int sum3 = findSum(arr, j + 1, n - 1);

            if(sum1 == sum2 && sum2 == sum3){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> arr = {0, 3, -3, 0, 0};
    vector<int> result = findSplit(arr);
    cout << "The indices of the split array: " << result[0] << " " <<result[1];
    return 0;
}