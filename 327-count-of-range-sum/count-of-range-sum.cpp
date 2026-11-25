class Solution {
public:
    long long mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        long long ans = mergeSort(prefix, left, mid, lower, upper)
                      + mergeSort(prefix, mid + 1, right, lower, upper);

        int j = mid + 1;
        int k = mid + 1;
        int t = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right && prefix[j] - prefix[i] < lower)
                j++;

            while (k <= right && prefix[k] - prefix[i] <= upper)
                k++;

            ans += k - j;
        }

        vector<long long> temp;
        int i = left;

        while (i <= mid && t <= right) {
            if (prefix[i] <= prefix[t])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[t++]);
        }

        while (i <= mid)
            temp.push_back(prefix[i++]);

        while (t <= right)
            temp.push_back(prefix[t++]);

        for (int p = 0; p < temp.size(); p++)
            prefix[left + p] = temp[p];

        return ans;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return mergeSort(prefix, 0, n, lower, upper);
    }
};