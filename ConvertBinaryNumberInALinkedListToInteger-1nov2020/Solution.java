public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

class Solution {
    public int getDecimalValue(ListNode head) {
        ListNode currentNode = head;
        int decimalValue = 0;
        while (currentNode != null) {
            decimalValue = decimalValue << 1;
            decimalValue = decimalValue | currentNode.val;
            currentNode = currentNode.next;
        }
        return decimalValue;
    }
}
