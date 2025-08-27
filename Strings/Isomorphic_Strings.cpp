#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// ---------------- BRUTE FORCE 1 ----------------
// Check mapping by comparing each pair
class SolutionBrute1 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if ((s[i] == s[j] && t[i] != t[j]) ||
                    (s[i] != s[j] && t[i] == t[j])) {
                    return false;
                }
            }
        }
        return true;
    }
};

// ---------------- BRUTE FORCE 2 ----------------
// Using two arrays for mapping
class SolutionBrute2 {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> mapS(256, -1);
        vector<int> mapT(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (mapS[s[i]] == -1 && mapT[t[i]] == -1) {
                mapS[s[i]] = t[i];
                mapT[t[i]] = s[i];
            } else {
                if (mapS[s[i]] != t[i] || mapT[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

// ---------------- OPTIMIZED ----------------
// Using unordered_map (clean + efficient)
class SolutionOptimized {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (mp1.find(s[i]) != mp1.end()) {
                if (mp1[s[i]] != t[i]) return false;
            } else {
                mp1[s[i]] = t[i];
            }

            if (mp2.find(t[i]) != mp2.end()) {
                if (mp2[t[i]] != s[i]) return false;
            } else {
                mp2[t[i]] = s[i];
            }
        }
        return true;
    }
};
