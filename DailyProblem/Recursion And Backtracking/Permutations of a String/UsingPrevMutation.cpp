#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n, greater<int>());

    do{
        for(int i = 0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }while (prev_permutation(arr, arr+n));

    return 0;
}