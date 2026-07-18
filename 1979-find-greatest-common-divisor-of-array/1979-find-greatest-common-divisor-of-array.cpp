class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        int low=nums[0];
        int high = nums[0];
        int n=nums.size();
        for(int i=1 ; i<n ; i++)
        {
            low=min(low,nums[i]);
            high=max(high,nums[i]);
        }
        
     
        return __gcd(low,high);
    }
};