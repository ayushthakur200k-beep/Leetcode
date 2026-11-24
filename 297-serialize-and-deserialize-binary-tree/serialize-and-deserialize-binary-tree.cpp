class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#";

        return to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string value;

        return build(ss);
    }

private:
    TreeNode* build(stringstream& ss) {
        string value;

        if (!getline(ss, value, ','))
            return nullptr;

        if (value == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(value));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }
};