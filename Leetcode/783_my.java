/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int minDiffInBST(TreeNode root) {
        int minDiff = 100000;
        int minNum = 0;
        if (root.left != null) {
            minNum = minLeftT(root.val, root.left);
            if (minNum < minDiff) {
                minDiff = minNum;
            }
            minNum = minDiffInBST(root.left);
            if (minNum < minDiff) {
                minDiff = minNum;
            }
        }
        if (root.right != null) {
            minNum = minRightT(root.val, root.right);
            if (minNum < minDiff) {
                minDiff = minNum;
            }
            minNum = minDiffInBST(root.right);
            if (minNum < minDiff) {
                minDiff = minNum;
            }
        }
        return minDiff;
    }

    public int minLeftT(int rootval, TreeNode root) {
        if (root.right == null) {
            return rootval - root.val;
        } else {
            return minLeftT(rootval, root.right);
        }
    }

    public int minRightT(int rootval, TreeNode root) {
        if (root.left == null) {
            return root.val - rootval;
        } else {
            return minRightT(rootval, root.left);
        }
    }
}