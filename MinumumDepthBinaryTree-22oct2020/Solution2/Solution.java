import java.util.*;
//STILL DOESNT EFFING WORK
//STILL DOESNT EFFING WORK
//STILL DOESNT EFFING WORK
//STILL DOESNT EFFING WORK
//STILL DOESNT EFFING WORK
//STILL DOESNT EFFING WORK
//STILL DOESNT EFFING WORK
//STILL DOESNT EFFING WORK

class Solution {
    static class qItem
    {
        TreeNode node;
        int depth;

        public qItem(TreeNode node, int depth)
        {
            this.node = node;
            this.depth = depth;
        }
    }
    public int minDepth(TreeNode root) {
        // Corner Case
        if (root == null)
            return 0;

        // Create an empty queue for level order tarversal
        Queue<qItem> q = new LinkedList<>();

        // Enqueue Root and initialize depth as 1
        qItem qi = new qItem(root, 1);
        q.add(qi);
        while (q.isEmpty() == false)
        {
            // Remove the front queue item
            qi = q.peek();
            q.remove();

            // Get details of the remove item
            TreeNode node = qi.node;
            int depth = qi.depth;

            // If this is the first leaf node seen so far
            // Then return its depth as answer



            if (node.left == null && node.right == null)
                return depth;



            if (node.left != null)
            {
                qi.node = node.left;
                qi.depth = depth + 1;
                q.add(qi);
            }
            if (node.right != null)
            {
                qi.node = node.right;
                qi.depth = depth + 1;
                q.add(qi);
            }

        }
        return 0;
    }
    public static void main(String args[]){
        Solution sol = new Solution();
        TreeNode n10 = new TreeNode(10);
        TreeNode n9 = new TreeNode(9);
        TreeNode n8 = new TreeNode(8);
        TreeNode n7 = new TreeNode(7,n8 , null );
        TreeNode n6 = new TreeNode(6,n7 , n10);
        TreeNode n5 = new TreeNode(5);
        TreeNode n4 = new TreeNode(4);
        TreeNode n3 = new TreeNode(3, n9, n6);
        TreeNode n2 = new TreeNode(2, n4, n5);
        TreeNode n1 = new TreeNode(1, n2, n3);
        System.out.println(sol.minDepth(n1));
    }
}
