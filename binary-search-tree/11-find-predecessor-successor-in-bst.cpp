class Solution {
public:
    void findPreSuc(Node* root, Node& &pre, Node* suc, int key){

        if(root == NULL)
            return;

        // finding successor -> key se just bada
        Node* cur = root;
        while(cur){

            if(key >= cur->data){
                // key bada hai to right me jana padega
                cur = cur->right;
            }
            else{
                // node value bada hai key se, ye successor ho sakta h
                // suc ko ans me leke left me jao, so that aur chota mil sake
                suc = cur;
                cur = cur->left;
            }
        }

        // finding predecessor -> key se just chota
        cur = root;
        while(cur){

            if(key > cur->data){

                pre = cur;
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
    }
}