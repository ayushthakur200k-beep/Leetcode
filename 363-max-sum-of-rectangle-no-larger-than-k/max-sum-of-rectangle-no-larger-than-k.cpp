class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = INT_MIN;

        for (int top = 0; top < m; top++) {
            vector<int> colSum(n, 0);

            for (int bottom = top; bottom < m; bottom++) {
                for (int j = 0; j < n; j++)
                    colSum[j] += matrix[bottom][j];

                set<int> prefixSet;
                prefixSet.insert(0);

                int prefix = 0;

                for (int x : colSum) {
                    prefix += x;

                    auto it = prefixSet.lower_bound(prefix - k);

                    if (it != prefixSet.end())
                        ans = max(ans, prefix - *it);

                    prefixSet.insert(prefix);
                }
            }
        }

        return ans;
    }
};