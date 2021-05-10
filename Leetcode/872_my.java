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
 
 
 /*
    I solve this problem by dfs(inorder traversal).
    Please pay attention to how to compare two List object through equals-mathod instead of "=="
 */
 
 
class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        dfs(root1, list1);
        dfs(root2, list2);
        // System.out.println(list1);
        // System.out.println(list2);
        if (list1.equals(list2)) {
            return true;
        }
        return false;
    }

    public void dfs(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        dfs(root.left, list);
        if (root.left == null && root.right == null) {
            list.add(root.val);
        }
        dfs(root.right, list);
        return;
    }
}