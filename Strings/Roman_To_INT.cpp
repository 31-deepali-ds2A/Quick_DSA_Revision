// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
         int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && val[s[i]] < val[s[i + 1]]) {
                sum -= val[s[i]];   // subtract if smaller than next
            } else {
                sum += val[s[i]];   // otherwise add
            }
        }
        return sum;
    }
    
};