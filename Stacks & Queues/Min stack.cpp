#include<stack>
using namespace std;


// O(1) & space-> O(N)
class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
       
    }

    void push(int val) {
       int mini;
      if (st.empty()) {
        mini = val;
      } else {
        mini = min(st.top().second, val);
      }
      st.push({val,mini});
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top() {
        int val=st.top().first;
        return val;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 //

 // using 2 stacks-> space O(2N)
 class MinStack {
    private:
    stack<int> s1;
    stack<int> s2;
public:
  
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x<=getMin()){
            s2.push(x);
        } 
    }

    void pop() {
        if(s1.top()==getMin()){
            s2.pop();
        }
            s1.pop();
    }
    
    int top() {
        return s1.top();
        
    }
    
    int getMin() {
        return s2.top();
        
    }
};

