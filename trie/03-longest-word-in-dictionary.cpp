struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void insert(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getNode(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string& word){
        
        Node* node = root;
        for(int i=0; i<word.length(); i++){

            if(!node->containsKey(word[i])){
                node->insert(word[i], new Node());
            }

            node = node->getNode(word[i]);
        }

        node->setEnd();
    }

    bool checkIfAllPrefixExists(string& word){

        Node* node = root;

        for(int i=0; i<word.length(); i++){

            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->getNode(word[i]);
            if(node->isEnd() == false){
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    // tc -> O(N * len)
    string longestWord(vector<string>& words){

        Trie trie;
        for(auto &word: words){
            trie.insert(word);
        }

        string longest="";
        for(auto &word: words){

            if(trie.checkIfAllPrefixExists(word)){

                if(word.length() > longest.length()){
                    longest = word;
                }
                else if(word.length() == longest.length() && word < longest){
                    longest = word;
                }
            }
        }

        return longest;
    }
};