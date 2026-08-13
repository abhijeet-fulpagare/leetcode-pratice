struct Node{
    int mx,pref,suff,len;

    char left,right;

    Node()
    {
        mx= pref = suff = len = 0;
        left = right = '#';
    }

    Node(char c)
    {
        left = right = c;
        mx= pref = suff = len = 1;
    }
};


Node merge(Node &a , Node &b)
{
    if(a.mx == 0)
    return b;

    if(b.mx == 0)
    return a;

    Node res;

    res.mx = max(a.mx,b.mx);
    res.pref = a.pref;
    res.suff = b.suff;
    res.left = a.left;
    res.right = b.right;
    res.len = a.len + b.len;
    
    if(a.right == b.left)
    {
        res.mx = max(a.suff+b.pref,res.mx);

        if(a.pref == a.len)
        {
            res.pref = a.len + b.pref;
        }

        if(b.suff == b.len)
        {
            res.suff = b.len + a.suff;
        }
    }

    return res;
}


void update(int low,int high,int ind,int udate_idx,vector<Node>&seg,char val)
{
    if(low == udate_idx && high == udate_idx)
    {
        seg[ind] = Node(val);
        return;
    }

    int mid = low + (high - low)/2;

    if(mid >= udate_idx)
    {
        update(low,mid,ind*2+1,udate_idx,seg,val);
    }
    else{
        update(mid+1,high,ind*2+2,udate_idx,seg,val);
    }

    seg[ind] = merge(seg[ind*2+1],seg[ind*2+2]);

    return;
}

void build(string &s,int low,int high,int ind,vector<Node>&seg)
{
    if(low == high)
    {
        seg[ind] = Node(s[low]);
        return;
    }


    int mid = low + (high - low)/2;

    build(s,low,mid,ind*2+1,seg);
    build(s,mid+1,high,ind*2+2,seg);

    seg[ind] = merge(seg[ind*2+1],seg[ind*2+2]);

    return;
}
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) 
    {
        int n = s.size();
        vector<Node>seg(n*4+1);

        vector<int>ans(queryIndices.size());

        build(s,0,n-1,0,seg);

        int j = 0;
        for(auto i:queryIndices)
        {
            update(0,n-1,0,i,seg,queryCharacters[j]);
            s[i] = queryCharacters[j];

            ans[j] = seg[0].mx;
            j++;
        }

        return ans;
        
    }
};