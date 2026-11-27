class SummaryRanges {
public:
    set<int> s;

    SummaryRanges() {
    }

    void addNum(int value) {
        s.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        if (s.empty())
            return ans;

        int start = *s.begin();
        int prev = start;

        auto it = next(s.begin());

        while (it != s.end()) {
            int x = *it;

            if (x != prev + 1) {
                ans.push_back({start, prev});
                start = x;
            }

            prev = x;
            it++;
        }

        ans.push_back({start, prev});

        return ans;
    }
};