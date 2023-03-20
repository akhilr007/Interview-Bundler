struct Node {
    Node* links[26];

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void insert(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getNode(char ch){
        return links[ch-'a'];
    }
};

class Solution {
public: 
    // tc -> O(n^2)
    int countSubstrings(string& word){

        int n = word.length();

        int cnt = 0;
        Node* root = new Node();

        for(int i=0; i<n; i++){

            Node* node = root;
            for(int j=i; j<n; j++){

                if(!node->containsKey(word[j])){

                    cnt++;
                    node->insert(word[j], new Node());
                }

                node = node->getNode(word[j]);
            }
        }

        return cnt + 1; // 1 is for empty substring;
    }
};