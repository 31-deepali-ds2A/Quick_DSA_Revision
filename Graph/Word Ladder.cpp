class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string> st(wordList.begin(),wordList.end()); // makes search esy in less time

        queue<pair<string,int>> q;
        q.push({beginWord,1}); // start with the first word

        while(!q.empty()){
            auto[word,steps]=q.front();
            q.pop();

            if(word==endWord) return steps; // found the endWord

            for(int i=0;i<word.size();i++){
                string original=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch; // check by replacing each char

                    // word exist in set
                    if(st.find(word)!=st.end()){
                        st.erase(word);  // remove it so that it cannot be picked again
                        q.push({word,steps+1});
                    }
                }
                word=original; // replace by it's original to try another sequence
            }
        }
        return 0;
    }
};