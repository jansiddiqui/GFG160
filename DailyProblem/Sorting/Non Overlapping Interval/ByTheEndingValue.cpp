#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int minRemoval(vector<vector<int> >& intervals) {
    int cnt = 0;
    sort(intervals.begin(), intervals.end(), compare);
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < end)
            cnt++;
        else
            end = intervals[i][1];
    }

    return cnt;
}

int main() {
    vector<vector<int>> intervals = 
                    {{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << minRemoval(intervals) << endl;
}