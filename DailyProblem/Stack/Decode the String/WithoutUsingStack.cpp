#include<bits/stdc++.h>
using namespace std;

string decodeString(string &s){
    string res = "";
    for(int i=0;i<s.length();i++){
        if(s[i] != ']'){
            res.push_back(s[i]);
        }
        else{
            string temp = "";
            while(!res.empty() && res.back() != '['){
                temp.push_back(res.back());
                res.pop_back();
            }
            reverse(temp.begin(), temp.end());
            res.pop_back();

            string num = "";
            while(!res.empty() && res.back() >= '0' && res.back() <= '9'){
                num.push_back(res.back());
                res.pop_back();
            }
            reverse(num.begin(), num.end());
            int p=stoi(num);

            while(p--){
                res.append(temp);
            }
        }
    }
    return res;
}

int main(){
    string s = "3[a2[c]]";
    cout<<decodeString(s)<<endl;
    return 0;
}