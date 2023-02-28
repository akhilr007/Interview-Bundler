// this version will pass testcases in gfg but fail in leetcode
// but can be enough for interviews
class Solution{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){

        vector<vector<string>> ans; // use to store all the shortest paths from begin_word -> end_word

        unordered_set<string> st(wordList.begin(), wordList.end()); // to find in O(1) if the word exists or not

        queue<vector<string>> q;
        q.push({beginWord});

        vector<string> usedOnLevel; // words that are used will be stored in usedOnLevel
        usedOnLevel.push_back(beginWord);

        int level=0; // current_level

        while(!q.empty()){

            vector<string> vec = q.front();
            q.pop();

            if(vec.size() > level){
                level++;
                // delete all the used words from the set
                for(auto words: usedOnLevel) st.erase(words);
                usedOnLevel.clear();
            }

            string word = vec.back(); // last word is the word we transformed from the old word
            if(word == endWord){

                if(ans.size() == 0) ans.push_back(vec);
                else if(ans[0].size() == vec.size()) ans.push_back(vec);
            }

            for(int i=0; i<word.length(); i++){

                char originalChar = word[i];
                for(char ch='a'; ch<='z'; ch++){

                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        usedOnLevel(word);
                        q.push(vec);

                        // but also remove the last word before moving on so that to add new path
                        vec.pop_back();
                    }
                }

                word[i] = originalChar;
            }
        }

        return ans;
    }
};