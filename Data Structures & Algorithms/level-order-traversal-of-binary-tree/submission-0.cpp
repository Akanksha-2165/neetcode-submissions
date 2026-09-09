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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL)
            return ans;
        
        q.push(root);

        while(!q.empty())   {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++)   {
                TreeNode *curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);
            }
            ans.push_back(level);
        }        
        return ans;
    }
};
//bfs is level order traversal hence better than using dfs

// OPTIMAL - BFS / Level Order Traversal
// Use a queue to process the tree level by level.
// Store the current queue size to know how many nodes belong
// to the current level. Process them, store their values,
// and add their children for the next level.
// Time Complexity: O(N)     Space Complexity: O(N)
