class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) 
    {
        set<int>s;
        for(auto i:nums)
        {
            s.insert(i);
        }
        int no = k;
        while(s.count(no) == 1)
            no+=k;

        return no;
        

    
        
    }
};