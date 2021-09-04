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

function isPalindrome(head: ListNode | null): boolean {
    const values: number[] = [];
    while (head) {
        values.push(head.val);
        head = head.next;
    }

    const lastIndex = values.length - 1;
    for (let i = 0; i < lastIndex / 2; i++) {
        if (values[i] !== values[lastIndex - i]) {
            return false;
        }
    }
    return true;
}
