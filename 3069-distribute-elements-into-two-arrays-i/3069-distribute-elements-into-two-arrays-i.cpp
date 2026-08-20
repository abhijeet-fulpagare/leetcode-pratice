class Solution {
public:
    vector<int> resultArray(vector<int>& nums) 
    {
        vector<int>l1,l2;

        int n = nums.size();
        l1.push_back(nums[0]);
        l2.push_back(nums[1]);
        for(int i=2 ; i<n ; i++)
        {
            if(l1.back() > l2.back())
            {
                l1.push_back(nums[i]);
            }
            else{
                l2.push_back(nums[i]);
            }
        }

        vector<int>ans;

        for(auto i:l1)
        {
            ans.push_back(i);
        }

        for(auto i:l2)
        {
            ans.push_back(i);
        }
        
        return ans;
    }
};