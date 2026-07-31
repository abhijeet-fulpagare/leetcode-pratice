class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<vector<int>,vector<string>>mp;

        int n = strs.size();

        for(int i=0 ; i<n ; i++)
        {
            vector<int>freq(26,0);
            for(auto c : strs[i])
            {
                freq[c-'a']++;
            }

            mp[freq].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }

        return ans;
        

        
    }
};