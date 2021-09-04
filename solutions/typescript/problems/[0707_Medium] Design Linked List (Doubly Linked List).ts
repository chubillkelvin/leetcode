// @ts-ignore
class MyNode {
    val: number;
    prev: MyNode | null;
    next: MyNode | null;
    constructor(val?: number, prev?: MyNode | null, next?: MyNode | null) {
        this.val = val ?? 0;
        this.prev = prev ?? null;
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
        this.head = new MyNode(val, null, this.head);
        if (this.size > 0) {
            this.head.next!.prev = this.head;
        }
        this.size++;
    }

    addAtTail(val: number): void {
        if (this.size === 0) {
            this.addAtHead(val);
        } else {
            const node = this.getNodeAtIndex(this.size - 1)!;
            node.next = new MyNode(val, node);
            this.size++;
        }
    }

    addAtIndex(index: number, val: number): void {
        if (index < 0 || index > this.size) return;

        if (index === 0) {
            this.addAtHead(val);
        } else {
            const nodePrev = this.getNodeAtIndex(index - 1)!;
            const nodeNext = this.getNodeAtIndex(index);
            const newNode = new MyNode(val, nodePrev, nodeNext);
            nodePrev.next = newNode;
            if (nodeNext) {
                nodeNext.prev = newNode;
            }
            this.size++;
        }
    }

    deleteAtIndex(index: number): void {
        if (index < 0 || index >= this.size) return;

        if (index === 0) {
            this.head = this.head!.next;
            if (this.head) {
                this.head.prev = null;
            }
        } else {
            const nodePrev = this.getNodeAtIndex(index - 1)!;
            const nodeNext = this.getNodeAtIndex(index + 1);
            nodePrev.next = nodeNext;
            if (nodeNext) {
                nodeNext.prev = nodePrev;
            }
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
