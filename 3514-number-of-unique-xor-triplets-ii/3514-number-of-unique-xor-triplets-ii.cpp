class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairXor;
        unordered_set<int> ans;

        int n = nums.size();

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                pairXor.insert(nums[i]^nums[j]);

        for(int x : pairXor)
            for(int v : nums)
                ans.insert(x ^ v);

        return ans.size();
    }
};