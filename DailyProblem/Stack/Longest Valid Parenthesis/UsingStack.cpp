#include<bits/stdc++.h>
using namespace std;

int maxLength(string s){
    stack<int> st;

    st.push(-1);
    int maxLen = 0;

    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(i);
        }else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }else{
                maxLen = max(maxLen, i-st.top());
            }
        }
    }
    return maxLen;
}

int main(){
    string s = ")()())";
    cout<<maxLength(s)<<endl;
    return 0;
}