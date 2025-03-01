#include<bits/stdc++.h>
using namespace std;

string decodeString(string &s){
    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(s[i] != ']'){
            st.push(s[i]);
        }
        else{
            string temp;

            while(!st.empty() && st.top() != '['){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            st.pop();

            string num;

            while(!st.empty() && isdigit(st.top())){
                num = st.top() + num;
                st.pop();
            }

            int number = stoi(num);
            string repeat;

            for(int j=0;j<number;j++){
                repeat.append(temp);
            }
            for(char c : repeat){
                st.push(c);
            }
        }
    }
    string res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string str = "3[b2[ca]]";
    cout << decodeString(str);
    return 0;
}