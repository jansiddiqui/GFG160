// C++ program to find the minimum page limit by iterating
// over all possible page limits

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to check if books can be allocated to
// all k students without exceeding 'pageLimit'
bool check(vector<int> &arr, int k, int pageLimit) {
    
    // Starting from the first student
    int cnt = 1;
    int pageSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        
        // If adding the current book exceeds the page 
        // limit, assign the book to the next student
        if(pageSum + arr[i] > pageLimit) {
            cnt++;
            pageSum = arr[i];
        }
        else {
            pageSum += arr[i];
        }
    }
    
      // If books can assigned to less than k students then
    // it can be assigned to exactly k students as well
    return (cnt <= k);
}

int findPages(vector<int> &arr, int k) {
    
    // If number of students are more than total books
    // then allocation is not possible
    if(k > arr.size())
        return -1;
        
    // Minimum and maximum possible page limits
    int minPageLimit = *max_element(arr.begin(), arr.end());
    int maxPageLimit = accumulate(arr.begin(), arr.end(), 0);
    
    // Iterating over all possible page limits
    for(int i = minPageLimit; i <= maxPageLimit; i++) {
        
        // Return the first page limit with we can
        // allocate books to all k students
        if(check(arr, k, i))
            return i;
    }
    
    return -1;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(arr, k);
    return 0;
}
