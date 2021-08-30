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

// Floyd's Tortoise and Hare
function floydDetectCycle(head: ListNode | null): ListNode | null {
    if (head === null) return null;

    let pointer1: ListNode | null = head;
    let pointer2: ListNode | null = head;

    let intersection = (() => {
        do {
            pointer1 = pointer1?.next || null;
            pointer2 = pointer2?.next?.next || null;
            if (pointer1 && pointer2 && pointer1 === pointer2) return pointer1;
        } while (pointer1 && pointer2);
        return null;
    })();

    if (intersection) {
        let pointer3: ListNode | null = head;
        while (intersection !== pointer3) {
            intersection = intersection?.next || null;
            pointer3 = pointer3?.next || null;
        }
        return intersection;
    } else {
        return null;
    }
}
