/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root)
        {
            if (root == NULL)
                return {};
            deque<pair<TreeNode*, int>> q;
            q.push_back({root, 0});

            vector<pair<int, int>> s;
            while (!q.empty())
            {
                auto node = q.front().first;
                auto level = q.front().second;
                q.pop_front();
                s.push_back({node->val, level});
                if (node->left)
                    q.push_back({node->left, level+1});
                if (node->right)
                    q.push_back({node->right, level+1});
            }
            auto last_level = s.back().second;
            vector<vector<int>> ans(last_level+1, vector<int>{});

            for (auto &n : s)
                ans[last_level-n.second].push_back(n.first);
            return ans;
        }
};
