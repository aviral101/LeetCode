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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int a = 1;
        while(q.size() > 0)
        {
            vector<int> vec;
            vector<TreeNode*> v;
            while(q.size() != 0)
            {
                v.push_back(q.front());
                vec.push_back((q.front())->val);
                q.pop();
            }
            ans.push_back(vec);
            if(a == 1)
            {
                for(int i = v.size() - 1; i>=0; i--)
                {
                    if(v[i]->right != NULL)
                        q.push(v[i]->right);
                    if(v[i]->left != NULL)
                        q.push(v[i]->left);
                }
                a = 2;
            }
            else if (a == 2)
            {
                for(int i = v.size() - 1; i>=0; i--)
                {
                    if(v[i]->left != NULL)
                        q.push(v[i]->left);
                    if(v[i]->right != NULL)
                        q.push(v[i]->right);
                    
                }
                a = 1;
            }
        }
        return ans;
    }
};