#include<bits/stdc++.h>
using namespace std;

class SpecialStack{
    private:
        stack<pair<int, int>> s;
    public:
        SpecialStack(){
            
        }

        void push(int x){
            int newMin = s.empty() ? x : min(x, s.top().second);
            s.push({x, newMin});
        }
        void pop(){
            if(!s.empty()){
                s.pop();
            }
        }
        int peek(){
            if(!s.empty()){
                return -1;
            }
            int top = s.top().first;
            return top;
        }
        int getMin(){
            if(s.empty()){
                return -1;
            }
            int mn = s.top().second;
            return mn;
        }
};

int main(){
    SpecialStack ss;

    ss.push(2);
    ss.push(3);
    cout<<ss.peek()<<" ";
    ss.pop();
    cout << ss.getMin() << " ";
    ss.push(1);
    cout << ss.getMin() << " ";
}