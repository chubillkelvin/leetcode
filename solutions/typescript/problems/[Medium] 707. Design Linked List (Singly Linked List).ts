// @ts-ignore
class MyNode {
    val: number = 0;
    next: MyNode | null = null;
    constructor(val?: number, next?: MyNode | null) {
        this.val = val ?? 0;
        this.next = next ?? null;
    }
}

// @ts-ignore
class MyLinkedList {
    size: number;
    head: MyNode | null;

    constructor() {
        this.size = 0;
        this.head = null;
    }

    get(index: number): number {
        return this.getNodeAtIndex(index)?.val ?? -1;
    }

    addAtHead(val: number): void {
        this.head = new MyNode(val, this.head);
        this.size++;
    }

    addAtTail(val: number): void {
        if (this.size === 0) {
            this.addAtHead(val);
        } else {
            this.getNodeAtIndex(this.size - 1)!.next = new MyNode(val);
            this.size++;
        }
    }

    addAtIndex(index: number, val: number): void {
        if (index < 0 || index > this.size) return;

        if (index === 0) {
            this.addAtHead(val);
        } else {
            this.getNodeAtIndex(index - 1)!.next = new MyNode(val, this.getNodeAtIndex(index));
            this.size++;
        }
    }

    deleteAtIndex(index: number): void {
        if (index < 0 || index >= this.size) return;

        if (index === 0) {
            this.head = this.head!.next;
        } else {
            this.getNodeAtIndex(index - 1)!.next = this.getNodeAtIndex(index + 1);
        }
        this.size--;
    }

    private getNodeAtIndex(index: number): MyNode | null {
        if (index < 0 || index >= this.size) return null;
        let count = index;
        let curr = this.head;
        while (count > 0) {
            curr = curr!.next;
            count--;
        }
        return curr;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */
