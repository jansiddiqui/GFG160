#include <bits/stdc++.h>
using namespace std;

int countfreq(vector<int> &arr, int target) {
    int l = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int r = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

    return r - l;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 5, 5, 5, 5};
    int target = 5;
    cout << countfreq(arr, target);
    return 0;
}
