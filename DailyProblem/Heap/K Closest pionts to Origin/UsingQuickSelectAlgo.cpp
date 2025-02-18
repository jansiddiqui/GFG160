#include <iostream>
#include <vector>

using namespace std;

int squaredDis(vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
}

int partition(vector<vector<int>>& points, int left, int right) {
    
    vector<int> pivot = points[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (squaredDis(points[j]) <= squaredDis(pivot)) {
            swap(points[i], points[j]);
            i++;
        }
    }
    swap(points[i], points[right]);
    
    return i;
}

void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
    if (left <= right) {
        int pivotIdx = partition(points, left, right);
        
        int leftCnt = pivotIdx - left + 1;
        if (leftCnt == k) 
            return;
        
        if (leftCnt > k)
            quickSelect(points, left, pivotIdx - 1, k);
            
        else 
            quickSelect(points, pivotIdx + 1, right, k - leftCnt);
    }
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
    quickSelect(points, 0, points.size() - 1, k);
    
    return vector<vector<int>> (points.begin(), points.begin() + k);
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, 
                            {5, -1}, {3, 2}, {1, 1}};
    int k = 3;
    
    vector<vector<int>> res = kClosest(points, k);
    
    for (vector<int> point : res) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    return 0;
}
