class Solution {
public:
    vector<int> getMax(vector<int>& nums, int k) {
        int remove = nums.size() - k;
        vector<int> st;

        for (int x : nums) {
            while (!st.empty() && remove > 0 && st.back() < x) {
                st.pop_back();
                remove--;
            }

            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        return j == b.size() ||
               (i < a.size() && a[i] > b[j]);
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int low = max(0, k - (int)nums2.size());
        int high = min(k, (int)nums1.size());

        for (int i = low; i <= high; i++) {
            vector<int> a = getMax(nums1, i);
            vector<int> b = getMax(nums2, k - i);

            vector<int> cur = merge(a, b);

            if (greater(cur, 0, ans, 0))
                ans = cur;
        }

        return ans;
    }
};