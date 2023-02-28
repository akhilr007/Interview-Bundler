class Solution{
public:
    // time complexity -> O(N for queue * word_length * 26 ) 
    // space complexity -> O(N for queue + N for set)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        st.erase(beginWord);

        while(!q.empty()){

            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            for(int i=0; i<word.length(); i++){
                char originalChar = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = originalChar;
            }
        }

        return 0;
    }
};