class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();

        int odd =0,even = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(nums1[i] % 2 == 0)
            even++;
            else
            odd++;
        }

        int f = 1;
        for(int i=0 ; i<n ; i++)
        {
            if(nums1[i] % 2 != 0)
            {
                if(odd <=1)
                {
                    f=0;
                    break;
                }

            }
        }

        if(f)
        return 1;

        f = 1;
        for(int i=0 ; i<n ; i++)
        {
            if(nums1[i] % 2 == 0)
            {
                if(odd <= 0)
                {
                    f=0;
                    break;
                }
            }
        }

        if(f)
        return 1;


        return 0;

    }
};