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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair <int, pair<TreeNode*, TreeNode*> > > q;
        if(root->val == x || root->val == y)
            return false;
        q.push({1, {root, NULL}});
        TreeNode* parent1 = NULL;
        TreeNode* parent2 = NULL;
        int level1 = -1;
        int level2 = -1;
        while(!q.empty())
        {
            pair<int, pair<TreeNode*, TreeNode*> > p = q.front();
            q.pop();
            TreeNode* curr = p.second.first;
            TreeNode* parent = p.second.second;
            int level = p.first;
            if(curr->val == x || curr->val == y)
            {
                if(level1 == -1)
                {
                    level1 = level;
                    parent1 = parent;
                }
                else
                {
                    level2 = level;
                    parent2 = parent;
                    if(level1 != level2)
                        return false;
                    if(parent1 == parent2)
                        return false;
                    return true;
                }
            }
            if(curr->left != NULL)
            {
                q.push({level + 1, {curr->left, curr}});
            }
            if(curr->right != NULL)
            {
                q.push({level + 1, {curr->right, curr}});
            }
        }
        return true;
    }
};