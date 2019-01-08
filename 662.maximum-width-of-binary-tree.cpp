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
        vector<pair<int, int>> pos;
        int widthOfBinaryTree(TreeNode* root)
        {
            if (root == NULL)
                return {0};
            queue<pair<int, TreeNode*>> queue;
            queue.push(pair<int, TreeNode*>{1, root});
            vector<int> result;
           
            while (!queue.empty())
            {
                int node_count = queue.size();
                int left = queue.front().first;
                while (node_count > 0)
                {
                    pair<int, TreeNode*> cur = queue.front();
                    queue.pop();
                    if (node_count == 1)
                    {
                        int right = cur.first;
                        result.push_back(right-left+1);
                    }
                    if (cur.second->left != NULL)
                        queue.push(pair<int, TreeNode*>{cur.first*2, cur.second->left});
                    if (cur.second->right != NULL)
                        queue.push(pair<int, TreeNode*>{cur.first*2+1, cur.second->right});
                    node_count -= 1;
                }
            }
            return *max_element(result.begin(), result.end());
        }
};
