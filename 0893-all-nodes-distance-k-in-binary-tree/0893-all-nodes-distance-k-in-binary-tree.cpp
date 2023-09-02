/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int n = 0;
    vector<int> v;
    void find(TreeNode *root, int k)
    {
        if(root == NULL) return;
        if(k == 1)
        {
            v.push_back(root->val);
            return;
        }
        find(root->left,k-1);
        find(root->right, k-1);
        return;
    }
    TreeNode* calc(TreeNode* root, TreeNode* target, int &k)
    {
        if(root == NULL) return NULL;
        if(root == target)
        {
            if(k == 0) 
            {
                v.push_back(root->val);
                return NULL;
            }
            find(root->left,k);
            find(root->right,k);
            k--;
            return root;
        }
        TreeNode* a, *b;
        a = calc(root->left,target,k);
        b = calc(root->right, target,k);
        if(a == target)
        {
            if(k == 0) 
            {
                v.push_back(root->val);
                return NULL;
            }
            find(root->right,k);
            k--;
            return a;
        }
        else if(b == target)
        {
            if(k == 0) 
            {
                v.push_back(root->val);
                return NULL;
            }
            find(root->left,k);
            k--;
            return b;
        }
        else
        {
            return NULL;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        calc(root,target,k);
        return v;
    }
};