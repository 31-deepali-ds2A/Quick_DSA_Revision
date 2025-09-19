#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        int i=0;

        while(i<n){
            bool alive=true;
            while(!st.empty() && (st.top()>0 && asteroids[i]<0)){

                if(st.top()<-asteroids[i]){
                    st.pop();
                    continue;
                }
                else if(st.top()==(-asteroids[i])){
                    st.pop();
                    // both explodes
                }
                 alive = false; 
                    break;
            }
            if (alive) st.push(asteroids[i]); // survived
            i++;
        }

         vector<int> res(st.size());
         for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};