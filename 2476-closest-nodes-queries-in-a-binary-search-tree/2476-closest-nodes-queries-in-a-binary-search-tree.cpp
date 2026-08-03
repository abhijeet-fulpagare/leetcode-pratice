class Solution {
public:
    vector<int> nums;

    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;

        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        inorder(root);

        vector<vector<int>> ans;

        for(int q : queries)
        {
            vector<int> temp(2);

  
            auto it1 = upper_bound(nums.begin(), nums.end(), q);

            if(it1 == nums.begin())
                temp[0] = -1;
            else
            {
                --it1;
                temp[0] = *it1;
            }

            auto it2 = lower_bound(nums.begin(), nums.end(), q);

            if(it2 == nums.end())
                temp[1] = -1;
            else
                temp[1] = *it2;

            ans.push_back(temp);
        }

        return ans;
    }
};