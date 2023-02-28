/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<TreeNode*> res;
    map<string, int> mp;
    string pre(TreeNode *root)
    {
        if (!root) return "";

        string s = "(" + pre(root->left) + ")" + to_string(root->val) + "(" +
            pre(root->right) + ")";
        mp[s]++;
        if (mp[s] == 2) res.push_back(root);

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode *root)
    {

        if (!root) return {};

        pre(root);

        return res;
    }
};