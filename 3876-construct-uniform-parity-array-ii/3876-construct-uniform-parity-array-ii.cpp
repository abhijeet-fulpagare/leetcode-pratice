class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int oddn = INT_MAX;

        for (int x : nums1) {
            if (x % 2 != 0)
                oddn = min(oddn, x);
        }

        if (oddn == INT_MAX)
            return true;


        for (int x : nums1) {
            if (x % 2 == 0 && x < oddn)
                return false;
        }

        return true;
    }
};