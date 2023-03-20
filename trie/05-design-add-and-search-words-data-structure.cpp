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

    bool searchUtil(string& word, Node* node, int index){

        if(index == word.length()){
            return node->isEnd();
        }

        if(word[index] == '.'){

            for(int i=0; i<26; i++){

                if(node->links[i] != NULL && searchUtil(word, node->links[i], index + 1)){
                    return true;
                }
            }

            return false;
        }
        else{
            if(node->containsKey(word[index])){
                node = node->getNode(word[index]);
                return searchUtil(word, node, index+1);
            }
            else{
                return false;
            }
        }
    }

    bool searchInTrie(string& word){

        Node* node = root;
        return searchUtil(word, node, 0);
    }
}

class WordDictionary{
public:
    Trie trie;
    WordDictionary(){

    }

    void addWord(string word){
        trie.insert(word);
    }

    bool search(string word){
        return trie.searchInTrie(word);
    }
};