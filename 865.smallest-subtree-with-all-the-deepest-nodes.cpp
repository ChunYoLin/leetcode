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
        TreeNode* subtreeWithAllDeepest(TreeNode* root)
        {
            return length_and_node(root).second;
        }

        pair<int, TreeNode*> length_and_node(TreeNode* root)
        {
            if (root == NULL)
                return {0, NULL};

            auto l_info = length_and_node(root->left);
            auto r_info = length_and_node(root->right);

            if (l_info.first == r_info.first)
                return {l_info.first+1, root};
            else if (l_info.first < r_info.first)
                return {r_info.first+1, r_info.second};
            else
                return {l_info.first+1, l_info.second};
        }
};
