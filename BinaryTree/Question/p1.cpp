

// https://leetcode.com/problems/subtree-of-another-tree/description/

// this will be the optimised solution if you make a good hash function
class Solution {
private:
    long long mod = 1000000007; 
    long long hash;
    bool flag = false;

public:
    long long HashTree(TreeNode* node) {
        if (!node) return 0;
        long long leftHash = HashTree(node->left);
        long long rightHash = HashTree(node->right);
        long long x = (leftHash * 31 + (node->val+10001) * 29 + rightHash * 37) % mod;
        return x;
    }

    long long HashTreeAndCheck(TreeNode* node) {
        if (!node) return 0;
        long long leftHash = HashTreeAndCheck(node->left);
        long long rightHash = HashTreeAndCheck(node->right);
        long long x = (leftHash * 31 + (node->val+10001) * 29 + rightHash * 37) % mod;
        if (x == hash) flag = true;
        return x;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        hash = HashTree(subRoot);
        HashTreeAndCheck(root);
        return flag;
    }
};



// this is my solution, we are basically checking for every node in the root that 
// is the subtree present

class Solution {
public:
    bool isIdentical(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL && root2 != NULL){
            return false;
        }
        if(root1 != NULL && root2 == NULL){
            return false;
        }

        bool left = isIdentical(root1->left, root2->left);
        bool right = isIdentical(root1->right, root2->right);
        bool isEqual = root1->val == root2->val;

        return left && right && isEqual;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();

            if(isIdentical(top, subRoot)){
                return true;
            }
            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
        }
        return false;
    }
};
