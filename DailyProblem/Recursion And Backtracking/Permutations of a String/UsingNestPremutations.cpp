#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);

    do{
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(arr, arr+n));
    return 0;
}