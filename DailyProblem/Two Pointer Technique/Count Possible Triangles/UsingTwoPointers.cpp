#include<bits/stdc++.h>
using namespace std;

int countTriangles(vector<int> &arr){
    int res = 0;
    sort(arr.begin(), arr.end());

    for(int i = 2; i < arr.size(); i++){
        int left = 0, right = i -1;
        while(left < right){
            if(arr[left] + arr[right] > arr[i]){
                res += right - left;
                right--;
            }
            else{
                left++;
            }
        }
    }
    return res;
}
int main(){
    vector<int> arr = {4, 6, 3, 7};
    cout << countTriangles(arr);
    return 0;
}