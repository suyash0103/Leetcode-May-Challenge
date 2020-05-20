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
    int ans;
    int i;
    vector<int> v;
    void find(TreeNode* root, int k)
    {
        if(root == NULL)
            return;
        find(root->left, k);
        v.push_back(root->val);
        if(v.size() == k)
            ans = v[v.size() - 1];
        find(root->right, k);
        // i++;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // int ans;
        find(root, k);
        cout << ans;
        return ans;
    }
};