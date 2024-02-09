// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:

// example1 max sum BST.png

// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
// Example 2:

// example2 max sum BST.png

// Input: root = [4,3,null,1,2]
// Output: 2
// Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
// Example 3:

// Input: root = [-4,-2,-5]
// Output: 0
// Explanation: All values are negatives. Return an empty BST.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 4 * 104].
// -4 * 104 <= Node.val <= 4 * 104


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
    struct SubtreeInfo {
        bool isBST;
        int sum, minVal, maxVal;
    };

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        traverse(root, maxSum);
        return maxSum;
    }

    SubtreeInfo traverse(TreeNode* node, int &maxSum) {
        if (!node) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        auto left = traverse(node->left, maxSum);
        auto right = traverse(node->right, maxSum);

        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            int sum = node->val + left.sum + right.sum;
            maxSum = max(maxSum, sum);
            int minVal = left.minVal != INT_MAX ? left.minVal : node->val;
            int maxVal = right.maxVal != INT_MIN ? right.maxVal : node->val;
            return {true, sum, minVal, maxVal};
        } else {
            return {false, 0, 0, 0};
        }
    }
};