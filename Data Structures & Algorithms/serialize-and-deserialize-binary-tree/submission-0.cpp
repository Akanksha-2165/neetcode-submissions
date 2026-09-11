/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "N ";

        return to_string(root->val) + " " +
               serialize(root->left)+
               serialize(root->right);
    }

    TreeNode* build(stringstream &ss)   {
        string value;
        ss >> value;

        if(value == "N")
            return NULL;

        TreeNode *node = new TreeNode(stoi(value));

        node -> left = build(ss);
        node -> right = build(ss);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return build(ss);
    }
};

// OPTIMAL - Preorder DFS + NULL Markers
// Serialize the tree using preorder traversal and store "N" for NULL nodes,
// so both the node values and the tree structure are preserved.
// During deserialization, read the values in the same preorder order
// and recursively rebuild the left and right subtrees.
// stringstream reads one value at a time and stoi converts it to an integer,
// so negative values are also handled correctly.
// Time Complexity: O(N)    Space Complexity: O(N)