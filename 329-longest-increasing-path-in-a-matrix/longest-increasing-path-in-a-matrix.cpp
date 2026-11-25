class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != 0)
            return dp[i][j];

        dp[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {

                dp[i][j] = max(dp[i][j],
                               1 + dfs(matrix, ni, nj));
            }
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, 0));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }
};