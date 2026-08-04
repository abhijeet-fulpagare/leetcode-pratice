class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int>ans;

        for(int i=0 ; i<n-1 ; i++)
        {
            int r = nums[i+1] - nums[i];

            if(r > 1)
            {
                int j = 1;
                while(r-- > 1)
                {
                    ans.push_back(nums[i]+j);
                    j++;
                }
            }
        }

        return ans;
    }
};