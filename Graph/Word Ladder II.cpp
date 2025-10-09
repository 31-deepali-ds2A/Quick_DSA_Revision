class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnWord;
        vector<vector<string>> ans;
        int level=0;

        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();

            if(vec.size()>level){
                level++;
                for(auto it:usedOnWord){
                    st.erase(it);
                }
            }

            string word=vec.back();
            if(word==endWord && ans.size()==0){
                ans.push_back(vec);
            }
            else if(word == endWord && vec.size()==ans[0].size()){
                ans.push_back(vec);
            }

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnWord.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }
};