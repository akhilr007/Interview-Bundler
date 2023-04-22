class BSTIterator{
private:
    stack<TreeNode*> bst;
    bool reverse = true;

    void pushAll(TreeNode* root){

        while(root){

            bst.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }

public:
    BSTIterator(TreeNode* root, bool reverse){

        this->reverse = reverse;
        pushAll(root);
    }

    int next(){

        TreeNode* topNode = bst.top();
        bst.pop();

        if(reverse){
            pushAll(topNode->left);
        }
        else{
            pushAll(topNode->right);
        }

        return topNode->val;
    }

    bool hasNext(){
        return bst.empty() == false;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k){

        BSTIterator l(root, false); // next
        BSTIterator r(root, true); // before

        int i = l.next();
        int j = r.next();

        while(i < j){

            if( i + j == k)
                return true;

            if(i + j < k)
                i = l.next();
            else 
                j = r.next();
        }

        return false;
    }
};