// time complexity -> O(1) on average
// space complexity -> O(height)
class BSTIterator {
private:
    stack<TreeNode*> bst;

    void pushAll(TreeNode* root){

        while(root){

            bst.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }

    int next(){

        TreeNode* topNode = bst.top();
        bst.pop();

        pushAll(topNode->right);
        return topNode->val;
    }

    bool hasNext(){
        return bst.empty() == false;
    }
};