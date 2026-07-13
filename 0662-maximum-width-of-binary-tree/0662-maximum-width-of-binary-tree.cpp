/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {

            int size = q.size();

            long long first = q.front().second;
            long long start, end;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                long long curr = q.front().second - first;
                q.pop();

                if(i == 0)
                    start = curr;
                if(i == size - 1)
                    end = curr;

                if(node->left)
                    q.push({node->left, 2 * curr + 1});

                if(node->right)
                    q.push({node->right, 2 * curr + 2});
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};