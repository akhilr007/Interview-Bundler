/*
brute:
    1. go to each node and find whether the given node is bst or not
    2. if bst, calculate its size
    time complexity -> O(n^2)

optimal:
    1. find left and right subtree is bst or not
    2. calculate largest value from left and smallest value from right and also size
    3. find if the curNode satisfies isBST, mark curNode isBST to true
    4. return 
    4. 
*/

class NodeInfo{
public:
    int max_value;
    int min_value;
    bool isBST;
    int size;
};

class Solution {
public:
    NodeInfo solve(Node* root, int& max_size){

        if(root == NULL){
            return { INT_MIN, INT_MAX, true, 0};
        }

        auto left = solve(root->left, max_size);
        auto right = solve(root->right, max_size);

        NodeInfo curNode;

        curNode.max_value = max(right.max_value, root->data);
        curNode.min_value = min(left.min_value, root->data);
        curNode.size = left.size + right.size + 1;

        if(left.isBST && right.isBST && (root->data > left.max_value && root->data < right.min_value)){
            curNode.isBST = true;
        }
        else{
            curNode.isBST = false;
        }

        if(curNode.isBST){
            max_size = max(max_size, curNode.size);
        }

        return curNode;
    }
    
    int largestBST(Node* root){
        int max_size = 0;
        NodeInfo nodeInfo = solve(root, max_size);
        return max_size;
    }
};