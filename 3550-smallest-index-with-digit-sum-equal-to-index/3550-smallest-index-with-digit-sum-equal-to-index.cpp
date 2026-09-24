class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {
        int n = nums.size();

        for(int i=0 ; i<n ; i++)
        {
            int no = nums[i];
            int s = 0;
            while(no != 0)
            {
                s+=no%10;
                no=no/10;
            }

            if(s == i)
            return i;
        }

        return -1;
        
    }
};