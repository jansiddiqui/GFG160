#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr){
    int left = 0, right = arr.size() - 1;

    while(left<right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

}

int main(){
    vector<int> arr={1,4,5,6, 7,3,0};
    reverseArray(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}