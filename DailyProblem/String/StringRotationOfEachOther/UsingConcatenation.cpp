#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool areRotations(string &s1, string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        string concatenated = s1 + s1;
        return concatenated.find(s2) != string::npos;
    }
};

int main() {
    Solution solution;
    string s1 = "ABCD";
    string s2 = "CDAB";
    
    if (solution.areRotations(s1, s2)) {
        cout << "Yes, they are rotations of each other." << endl;
    } else {
        cout << "No, they are not rotations of each other." << endl;
    }
    
    return 0;
}
