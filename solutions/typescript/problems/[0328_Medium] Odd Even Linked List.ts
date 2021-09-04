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

function oddEvenList(head: ListNode | null): ListNode | null {
    const evenHead = head?.next || null;
    let lastOdd: ListNode | null = head;
    let lastEven: ListNode | null = head?.next || null;
    let curr: ListNode | null = head?.next?.next || null;
    while (curr) {
        // odd
        if (lastOdd) {
            lastOdd.next = curr;
            lastOdd = curr;
        }

        curr = curr.next;
        // even
        if (lastEven) {
            lastEven.next = curr;
            lastEven = curr;
        }

        curr = curr?.next || null;
    }
    if (lastOdd) {
        lastOdd.next = evenHead;
    }
    return head;
}
