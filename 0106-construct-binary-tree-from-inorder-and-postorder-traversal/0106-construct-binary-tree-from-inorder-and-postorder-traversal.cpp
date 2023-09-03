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
    int n;
    TreeNode* findtree(vector<int> in, vector<int> po,unordered_map<int,int> mp, int l, int r)
    {
        if(l>r|| l < 0 || l >= in.size() || r < 0 || r >= in.size())
        {
            return NULL;
        }
        TreeNode* temp;
        temp = new TreeNode;
        temp->val = po[n];
        //cout<<temp->val<<" ";
        if(l == r)
        {
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        int m = mp[po[n]] - 1;
        // cout<<mp[po[n]]<<" "<<m<<" : m\n";
        if(m+1 <= r)
        {
            n--;
            temp->right = findtree(in,po,mp, m + 1,r);
        }
        // cout<<n<<" : n\n";
        if(m-1 >= l)
        {
            n--;
            temp->left = findtree(in,po,mp, l,m - 1);
        }
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size() - 1;
        if(n<0) return NULL;
        unordered_map<int,int> mp;
        for(int i = 0; i<=n; i++)
        {
            mp[inorder[i]] = i+1;
            // cout<<inorder[i]<<" "<<mp[inorder[i]]<<"\n";
        }

        return findtree(inorder,postorder,mp, 0,n);
    }
};