class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            tree[node] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }

    void updateTree(int node, int l, int r, int index, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid)
            updateTree(node * 2, l, mid, index, val);
        else
            updateTree(node * 2 + 1, mid + 1, r, index, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = l + (r - l) / 2;

        return query(node * 2, l, mid, ql, qr)
             + query(node * 2 + 1, mid + 1, r, ql, qr);
    }
};