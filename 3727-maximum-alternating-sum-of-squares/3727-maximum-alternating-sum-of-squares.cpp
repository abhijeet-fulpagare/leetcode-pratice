class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long>v(n,0);

        for(int i=0 ; i<n ; i++)
        {
            v[i] = (nums[i] * 1ll) * (nums[i] * 1ll);
        }

        sort(v.begin(),v.end());

        int i = 0;
        int j = n-1;

        long long ans = 0;

        
        while(i < j)
        {
            ans = ans + (v[j--] - v[i++]);
        }

        if(i == j)
        ans+= v[i];

        return ans;
    }
};