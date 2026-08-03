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

    TreeNode* f(TreeNode* root)
    {
        if(root == NULL)
        return NULL;

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        if(l == NULL && r == NULL)
        {
            return root;
        }
        root -> left = NULL;
        root ->right = NULL;


        TreeNode* lp = f(l);
        TreeNode* rp = f(r);

        if(lp != NULL && rp != NULL)
        {
            TreeNode* temp = lp;
            while(temp->right != NULL)
            {
                temp = temp->right;
            }

            temp->right = rp;
            root->right = lp;
        }

        if(lp == NULL && rp != NULL)
        {
            root->right = rp;
        }

        if(rp == NULL && lp != NULL)
        {
            root->right = lp;
        }

        return root;
                
    }
    void flatten(TreeNode* root) {
        
        TreeNode* r=f(root);

        return;
    }
};