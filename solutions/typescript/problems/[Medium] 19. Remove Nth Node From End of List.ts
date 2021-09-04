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

function removeNthFromEnd(head: ListNode | null, n: number): ListNode | null {
    if (head === null) return null;

    const newHead = new ListNode(0, head);
    let pointer1: ListNode | null = newHead;
    let pointer2: ListNode | null = head;

    while (pointer2) {
        n--;
        pointer2 = pointer2?.next || null;

        if (pointer2 === null) {
            if (n > 0) {
                return null;
            } else {
                pointer1!.next = pointer1!.next?.next || null;
            }
        }

        if (n <= 0) {
            pointer1 = pointer1?.next || null;
        }
    }
    return newHead.next;
}
