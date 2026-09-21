class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<long long> ans(k, 0);
        vector<long long> prev(k, 0);

        for(int x : nums)
        {
            vector<long long> curr(k, 0);

            curr[x % k]++;

            for(int r = 0; r < k; r++)
            {
                int nr = (r * (x % k)) % k;
                curr[nr] += prev[r];
            }

            for(int r = 0; r < k; r++)
            {
                ans[r] += curr[r];
            }

            prev = curr;
        }

        return ans;
    }
};