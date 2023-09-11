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
    vector<TreeNode*> v;
    void check(TreeNode* root)
    {
        if(root == NULL) return;
        check(root->left);
        v.push_back(root);
        check(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        check(root);
        int n = v.size();
        TreeNode* a,*b;
        a = NULL;
        b = NULL;
        for(int i = 1; i<n; i++)
        {
            // cout<<v[i]->val<<" ";
            if(v[i]->val < v[i-1]->val)
            {
                if(a == NULL)
                {
                    // cout<<"one\n";
                    a = v[i-1];
                    b = v[i];
                }
                else
                {
                    // cout<<"two\n";
                    b = v[i];
                }
            }
        }
        // cout<<a->val<<" "<<b->val<<"\n";
        int t = a->val;
        a->val = b->val;
        b->val = t;
    }
};