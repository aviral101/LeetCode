/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int split(vector<int> preorder,int root,int l, int r)
    {
        for(int i = l; i<= r; i++)
        {
            if(preorder[i] > root)
                return i - 1;
        }
        return r;
    }
    TreeNode* bst(vector<int> preorder, int l, int r, int n)
    {
        if(l == r)
        {
            TreeNode* temp = new TreeNode;
            temp->val = preorder[l];
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        if(l > r) return NULL;
        int m = split(preorder,preorder[l],l+1,r);
        TreeNode* temp = new TreeNode;
        temp->val = preorder[l];
        temp->left = bst(preorder,l+1,m,n);
        temp->right = bst(preorder,m+1,r,n);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder,0,preorder.size()-1,preorder.size());
    }
};