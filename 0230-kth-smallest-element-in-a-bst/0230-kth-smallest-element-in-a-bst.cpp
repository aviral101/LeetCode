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
    int ans = -1;
    int c = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(ans != -1) return ans;
        if(root == NULL) return ans;
        kthSmallest(root->left,k);
        c++;
        if(c == k)
        {
            ans = root->val;
        }
        kthSmallest(root->right,k);
        return ans;
    }
};