/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const headPointer = new ListNode(0);
    let carryOver = 0;
    let curr: ListNode = headPointer;
    while (l1 || l2 || carryOver) {
        curr.next = new ListNode((l1?.val || 0) + (l2?.val || 0) + carryOver);
        curr = curr.next;
        l1 = l1?.next || null;
        l2 = l2?.next || null;
        if (curr.val >= 10) {
            curr.val -= 10;
            carryOver = 1;
        } else {
            carryOver = 0;
        }
    }
    return headPointer.next;
}
