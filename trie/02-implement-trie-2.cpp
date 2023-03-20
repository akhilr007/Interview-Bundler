#include <bits/stdc++.h>

struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void insertChar(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getNode(char ch){
        return links[ch-'a'];
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void decreaseEnd(){
        cntEndWith--;
    }

    void decreasePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndWith;
    }

    int getPrefix(){
        return cntPrefix;
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
                node->insertChar(word[i], new Node());
            }

            node = node->getNode(word[i]);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string& word){

        Node* node = root;
        for(int i=0; i<word.length(); i++){

            if(!node->containsKey(word[i])){
                return 0;
            }

            node = node->getNode(word[i]);
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string& word){

        Node* node = root;
        for(int i=0; i<word.length(); i++){

            if(!node->containsKey(word[i])){
                return 0;
            }

            node = node->getNode(word[i]);
        }

        return node->getPrefix();
    }

    void erase(string& word){

        Node* node = root;
        for(int i=0; i<word.length(); i++){

            if(!node->containsKey(word[i])){
                return;
            }

            node = node->getNode(word[i]);
            node->decreasePrefix();
        }

        node->decreaseEnd();
    }

};