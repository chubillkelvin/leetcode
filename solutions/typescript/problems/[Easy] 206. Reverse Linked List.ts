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

function reverseList(head: ListNode | null): ListNode | null {
    if (head === null) return null;

    let newHead: ListNode | null = null;
    let curr: ListNode | null = head;
    while (curr) {
        const next: ListNode | null = curr.next;
        curr.next = newHead;
        newHead = curr;
        curr = next;
    }
    return newHead;
}
