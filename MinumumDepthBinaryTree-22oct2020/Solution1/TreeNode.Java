
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
    public static void main(String args[]){
        Solution sol = new Solution()   ;
        TreeNode n7 = new TreeNode(7);
        TreeNode n6 = new TreeNode(6);
        TreeNode n5 = new TreeNode(5, n7, null);
        TreeNode n4 = new TreeNode(4);
        TreeNode n3 = new TreeNode(3, null, n6);
        TreeNode n2 = new TreeNode(2, n4, n5);
        TreeNode n1 = new TreeNode(1, n2, n3);
        System.out.println(sol.minDepth(n1));
    }
}

class Solution {
    public int minDepth(TreeNode root) {
        //This is only true if the input tree is empty
        if (root == null) {
            return 0;
        }
        //If root is leaf node
        if (root.left == null && root.right == null ) {
            return 1;
        }
        //if it isn't leaf node
        if (root.left == null) {
            return minDepth(root.right) + 1;
        }
        if (root.right == null) {
            return minDepth(root.left) + 1;
        }
        return Math.min(minDepth(root.right), minDepth(root.left)) + 1;
    }
}
