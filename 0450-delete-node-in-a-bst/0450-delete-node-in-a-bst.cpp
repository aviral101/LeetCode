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
    TreeNode* del(TreeNode* root)
    {
        TreeNode *temp, *prev;
        temp = (root)->left;
        prev = root;
        while(temp != NULL && temp->right != NULL)
        {
            prev = temp;
            temp = temp->right;
        }
        if(temp == NULL) return NULL;
        if(prev->left == temp)
        {
            prev->left = temp->left;
        }
        else if(prev->right == temp)
        {
            prev->right = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp, *d, *prev;
        temp = root;
        if(temp == NULL) return NULL;
        prev = NULL;
        while(temp != NULL)
        {
            if(key < temp->val)
            {
                prev = temp;
                temp = temp->left;
            }
            else if(key > temp->val)
            {
                prev = temp;
                temp = temp->right;
            }
            else if(key == temp->val)
            {
                break;
            }
        }
        if(temp == NULL) 
        {
            cout<<"asdf\n";
            return root;
        }
        else
        {
            cout<<temp->val<<"\n";
        }
        d = del(temp);
        if(prev == NULL && temp == root)
        {
            if(d == NULL)
            {
                root = root->right;
            }
            else
            {
                root = d;
                d->left = temp->left;
                d->right = temp->right;
                // free(temp);
            }
        }
        else
        {
            if(prev->left == temp)
            {
                if(d == NULL)
                {
                    prev->left = temp->right;
                }
                else
                {
                    prev->left = d;
                    d->left = temp->left;
                    d->right = temp->right;
                    // free(temp);
                }
            }
            else
            {
                if(d == NULL)
                {
                    prev->right = temp->right;
                }
                else
                {
                    prev->right = d;
                    d->left = temp->left;
                    d->right = temp->right;
                    // free(temp);
                }
            }
        }
        return root;
    }
};