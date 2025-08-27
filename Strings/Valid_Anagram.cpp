#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// -------------------------------------------------------------
// Approach 1: Using map
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1, mp2;

        for(char ch : s) mp1[ch]++;
        for(char ch : t) mp2[ch]++;

        return mp1 == mp2;
    }
};

// -------------------------------------------------------------
// Approach 2: Using sorting
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// -------------------------------------------------------------
// Approach 3: Using unordered_map with optimization
class Solution3 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> freq;

        for(char ch : s) freq[ch]++;

        for(char ch : t) {
            if(freq.find(ch) == freq.end() || freq[ch] == 0) {
                return false;
            }
            freq[ch]--;
        }
        return true;
    }
};

// -------------------------------------------------------------
int main() {
    string s = "anagram";
    string t = "nagaram";

    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;

    cout << "Approach 1 (map): "
         << (sol1.isAnagram(s,t) ? "True" : "False") << endl;

    cout << "Approach 2 (sort): "
         << (sol2.isAnagram(s,t) ? "True" : "False") << endl;

    cout << "Approach 3 (unordered_map): "
         << (sol3.isAnagram(s,t) ? "True" : "False") << endl;

    return 0;
}
