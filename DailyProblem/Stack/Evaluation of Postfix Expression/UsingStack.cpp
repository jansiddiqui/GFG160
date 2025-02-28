#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(vector<string>& arr){
    stack<int> s;

    for(string token : arr){
        if(isdigit(token[0]) || (token.size() > 1 && token[0] == '-')){
            s.push(stoi(token));
        }
        else{
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();

            if(token == "+"){
                s.push(val1+val2);
            }else if(token == "-"){
                s.push(val2-val1);
            }else if(token == "*"){
                s.push(val1*val2);
            }else if(token == "/"){
                s.push(val2/val2);
            }
        }
    }
    return s.top();
}

int main(){
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    cout << evaluatePostfix(arr) << endl;
    return 0;
}