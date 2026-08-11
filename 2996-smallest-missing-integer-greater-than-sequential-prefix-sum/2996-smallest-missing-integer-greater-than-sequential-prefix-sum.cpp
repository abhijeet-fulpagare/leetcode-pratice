class Solution {
public:
    int missingInteger(vector<int>& nums) 
    {
        set<int>s;

        int n = nums.size();

        for(int i= 0 ;i<n ; i++)
        {
            s.insert(nums[i]);
        }

        int sum = 0;
        int seq = 0;
        for(int i=0 ; i<n-1 ; i++)
        {
            if(nums[i] == nums[i+1]-1)
            {
                seq++;
                sum+=nums[i];
            }
            else{
                if(seq >= 1)
                {
                    sum+=nums[i];
                }
                break;
            }
        }

        if(seq == n-1)
        {
            sum+=nums[n-1];
        }

        if(seq == 0)
        {
            sum = nums[0];
        }


        while(1)
        {
            if(s.count(sum))
            {
                sum++;
            }
            else{
                break;
            }
        }


        return  sum;
        
        




    }
};