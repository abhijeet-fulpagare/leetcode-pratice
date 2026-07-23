class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) 
    {
        int n=nums.size();

        if(n <= 2)
        {
            return n;
        }

        int no =n;

        int bitcnt=0;
        while(no != 0)
        {
            no = no >> 1;
            bitcnt++;
        }
        
        return pow(2,bitcnt);
    }
};