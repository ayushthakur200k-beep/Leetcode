class NestedIterator {
public:
    vector<int> nums;
    int index = 0;

    void flatten(vector<NestedInteger>& nestedList) {
        for (auto& x : nestedList) {
            if (x.isInteger())
                nums.push_back(x.getInteger());
            else {
                vector<NestedInteger> temp = x.getList();
                flatten(temp);
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        return nums[index++];
    }

    bool hasNext() {
        return index < nums.size();
    }
};