class Solution {
public:

    vector<int> findpge(vector<int>&nums,int &n)
    {
        vector<int>ans(n,0);

        int t = -1;
        
        for(int i=0 ; i<n ; i++)
        {
            t = max(t,nums[i]);
            ans[i] = t;
        }

        return ans;
    }

    vector<int> findnse(vector<int>&nums,int &n)
    {
        vector<int>ans(n,0);

        int t = INT_MAX;
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            t = min(t,nums[i]);
            ans[i] = t;
        }

        return ans;
    }



    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int>pge,nse;

        pge = findpge(nums,n);

        nse = findnse(nums,n);

        int ans = INT_MAX;
        for(int i=0 ; i<n ; i++)
        {
            if((pge[i] - nse[i]) <= k )
            {
                return i;
            }
        }

        return -1;
    }
};