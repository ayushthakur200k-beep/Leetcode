class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {nums[i], i};

        mergeSort(a, 0, n - 1, ans);

        return ans;
    }

    void mergeSort(vector<pair<int, int>>& a, int left, int right,
                   vector<int>& ans) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(a, left, mid, ans);
        mergeSort(a, mid + 1, right, ans);

        vector<pair<int, int>> temp;
        int i = left, j = mid + 1;
        int rightSmaller = 0;

        while (i <= mid && j <= right) {
            if (a[j].first < a[i].first) {
                temp.push_back(a[j]);
                rightSmaller++;
                j++;
            }
            else {
                ans[a[i].second] += rightSmaller;
                temp.push_back(a[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[a[i].second] += rightSmaller;
            temp.push_back(a[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(a[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++)
            a[left + k] = temp[k];
    }
};