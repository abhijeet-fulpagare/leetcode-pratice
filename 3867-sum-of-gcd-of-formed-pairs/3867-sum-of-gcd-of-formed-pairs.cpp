class Solution {
public:
    long long gcdSum(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>pre(n);

        int maxi = nums[0];

        pre[0] = maxi;

        for(int i=1 ; i<n ; i++)
        {
            maxi=max(maxi,nums[i]);
            pre[i] = __gcd(maxi ,nums[i]);
        }

        sort(pre.begin(),pre.end());
        int st=0;
        int en = n-1;
        long long ans=0;
        while(st < en)
        {
            int g= __gcd(pre[st],pre[en]);
            ans+=g;
            st++;
            en--;
        }
        return ans;
    }
};