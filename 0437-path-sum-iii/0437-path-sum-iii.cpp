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
    unordered_map<long,int> m;
    void check(TreeNode *root, int k, long s)
    {
        if(root == NULL) return;
        s += root->val;
        if(m[s-k] > 0)
        {
            c = (c +  m[s-k]);
        }
        m[s]++;

        check(root->left,k,s);
        check(root->right,k,s);
        m[s]--;
    }
    int pathSum(TreeNode* root, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        m[0] = 1;
        check(root,k,0);
        return c;
    }
};