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

function rotateRight(head: ListNode | null, k: number): ListNode | null {
    if (head === null) return null;

    // Make the linked-list circular
    let tail: ListNode | null = head;
    let count = 1;
    while (tail.next) {
        tail = tail.next;
        count++;
    }
    tail.next = head;

    // Define the cut
    let curr: ListNode = head;
    let next: ListNode = head.next!;
    let rotations = count - 1 - (k % count);
    while (rotations > 0) {
        curr = next;
        next = next.next!;
        rotations--;
    }
    curr!.next = null;
    return next;
}
