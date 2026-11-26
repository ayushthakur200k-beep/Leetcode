class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            int n = s.size();

            for (int j = 0; j <= n; j++) {
                if (isPalindrome(s, j, n - 1)) {
                    string left = s.substr(0, j);

                    if (mp.count(left) && mp[left] != i)
                        ans.push_back({i, mp[left]});
                }

                if (j > 0 && isPalindrome(s, 0, j - 1)) {
                    string right = s.substr(j);

                    if (mp.count(right) && mp[right] != i)
                        ans.push_back({mp[right], i});
                }
            }
        }

        return ans;
    }
};