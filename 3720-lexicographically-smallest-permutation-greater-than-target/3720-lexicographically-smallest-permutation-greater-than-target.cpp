class Solution {
private:
    string getRest(vector<int>& f)
    {
        string ans = "";

        for(int i = 0; i < 26; i++)
        {
            while(f[i] > 0)
            {
                ans += char('a' + i);
                f[i]--;
            }
        }

        return ans;
    }

public:
    string lexGreaterPermutation(string s, string target)
    {
        vector<int> f(26, 0);

        for(int i = 0; i < s.size(); i++)
            f[s[i] - 'a']++;

        int n = target.size();


        int pos = 0;

        while(pos < n && f[target[pos] - 'a'] > 0)
        {
            f[target[pos] - 'a']--;
            pos++;
        }

        string ans = "";

      
        for(int i = pos; i >= 0; i--)
        {
            if(i < pos && i < n)
            {
                f[target[i] - 'a']++;
            }

            int pos_idx = (i == n) ? -1 : target[i] - 'a';

          
            for(int k = pos_idx + 1; k < 26; k++)
            {
                if(f[k] > 0)
                {
                    ans += target.substr(0, i);
                    ans += char('a' + k);
                    f[k]--;
                    ans += getRest(f);
                    return ans;
                }
            }
        }

        return "";
    }
};