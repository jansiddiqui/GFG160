#include<bits/stdc++.h>
using namespace std;

bool checkMatch(char c1, char c2){
    if(c1 == '(' && c2 == ')') return true;
    if(c1 == '[' && c2 == ']') return true;
    if(c1 == '{' && c2 == '}') return true;
    return false;
}
bool isBalanced(string& s){
    int top = -1;
    for(int i=0; i<s.length(); ++i){
        if(top < 0 || !checkMatch(s[top], s[i])){
            ++top;
            s[top] = s[i];
        }
        else{
            --top;
        }
    }
    return top == -1;
}
int main(){
    string s = "{([])}";
    cout << (isBalanced(s) ? "true" : "false") << endl;
    return 0;
}