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
    int c = 0;
    void check(TreeNode *root, int k, unordered_map<long long,int> m, long long s)
    {
        if(root == NULL) return;
        s += root->val;
        if(m[s-k] > 0)
        {
            c = (c +  m[s-k])%1000000007;
        }
        m[s]++;

        check(root->left,k,m,s);
        check(root->right,k,m,s);
        s -= root->val;
        m[s]--;
    }
    int pathSum(TreeNode* root, int k) {
        unordered_map<long long,int> m;
        m[0] = 1;
        check(root,k,m,0);
        return c%1000000007;
    }
};