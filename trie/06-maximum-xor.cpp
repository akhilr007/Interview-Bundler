struct Node {
    Node* links[2];

    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    void insert(int bit, Node* node){
        links[bit] = node;
    }

    Node* getNode(int bit){
        return links[bit];
    }
};

class Trie {

private:
    Node* root;
     
public:
    Trie(){
        root = new Node();
    }

    void insert(int num){

        Node* node = root;
        for(int i=31; i>=0; i--){

            int bit = (num >> i) & 1;
            
            if(!node->containsKey(bit)){

                node->insert(bit, new Node());
            }

            node = node->getNode(bit);
        }
    }

    int getMax(int num){

        Node* node = root;
        int maxNum = 0;

        for(int i=31; i>=0; i--){

            int bit = (num >> i) & 1;

            if(node->containsKey(1 - bit)){
                
                maxNum = maxNum | (1<<i);
                node = node->getNode(1-bit);
            }
            else{
                node = node->getNode(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    // tc -> O(n * 32) + O(m * 32)
    int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2){

        Trie trie;
        for(auto &it : arr1){
            trie.insert(it);
        }

        int maxi=0;
        for(auto &it : arr2){
            maxi = max(maxi , trie.getMax(it));
        }

        return maxi;
    }
};