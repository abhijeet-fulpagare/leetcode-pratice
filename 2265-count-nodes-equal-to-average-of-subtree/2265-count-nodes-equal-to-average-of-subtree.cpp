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

    pair<int,int> f(TreeNode* root,int &cnt)
    {
        if(root == NULL)
        return {0,0};
        
        pair<int,int> left = f(root->left,cnt);
        pair<int,int> right = f(root->right,cnt);

        int curr = root->val + left.first + right.first;

        int nodes = 1 + left.second + right.second;

        if((curr/nodes) == root->val )
        cnt++;

        return {curr,nodes};




    }
    int averageOfSubtree(TreeNode* root) 
    {
        int cnt = 0;
        pair<int,int> p = f(root,cnt);
        return cnt;
    }
};