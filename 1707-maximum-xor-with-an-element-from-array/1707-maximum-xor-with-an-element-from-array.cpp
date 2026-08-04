class trie{

    trie* links[2];

    public:
    trie()
    {
        links[0] = links[1] = NULL;
    }

    bool isExists(bool c)
    {
        return (links[c] != NULL);
    }

    void insert(bool c,trie* Node)
    {
        links[c] = Node;
        return;
    }

    trie* next(bool c)
    {
        return links[c];
    }

};

struct cmp{
    bool operator()(const vector<int>&a,const vector<int>&b)
    {
        return a[1] < b[1];
    }
};
class Solution {
    trie *root;
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        root = new trie();
        int n = queries.size();
        vector<int>ans(n,0);

        for(int i= 0 ; i<n ; i++)
        {
            queries[i].push_back(i);
        }

        sort(nums.begin(),nums.end());

        sort(queries.begin(),queries.end(),cmp());

        int j=0;
        for(auto q:queries)
        {
            int x = q[0];
            int m = q[1];

            while(j<nums.size() && nums[j] <= m )
            {
                int no = nums[j++];
                trie *temp = root;

                for(int i=31 ; i >= 0 ; i--)
                {
                    bool k = ((no >> i) & 1);
                    if(!temp->isExists(k))
                    {
                        temp->insert(k,new trie());
                    }

                    temp = temp->next(k);
                }
            }

            int no = x;
            trie *temp = root;
            int curr = 0;
            bool ok = 1;
            for(int i=31 ; i >= 0 ; i--)
            {
                bool k = ((no >> i) & 1);

                if(temp->isExists(!k))
                {
                    curr = (curr | (1<<i));
                    temp = temp->next(!k);
                }
                else if(temp->isExists(k)){
                    temp = temp->next(k);
                }
                else{
                    ok = 0;
                    break;
                }
            }

            if(ok)
            {
                ans[q[2]] = curr;
            }
            else{
                ans[q[2]] = -1;
            }


        }

        return ans;
    }
};