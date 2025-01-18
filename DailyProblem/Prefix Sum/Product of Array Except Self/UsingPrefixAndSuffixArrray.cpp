#include<bits/stdc++.h>
using namespace std;

int n  =arr.size();
vector<int> preProduct(n), suffProduct(n), res(n);
preProduct[0]  = 1;
for(int  i=1;i<n;i++){
    preProduct[i] = arr[i - 1] * preProduct[i - 1];
}
suffProduct[n-1] = 1;
for(int j=n-2;j>=0;j--){
    suffProduct[j] = arr[j + 1] * suffProduct[j + 1];
}
for(int i =0;i<n;i++){
    res[i] = preProduct[i] * suffProduct[i];
}
return res;