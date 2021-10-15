// @ts-ignore
class DisjointSet {
    private root: number[] = [];
    private rank: number[] = [];

    constructor(size: number) {
        for (let i = 0; i < size; i++) {
            this.root[i] = i;
            this.rank[i] = 1;
        }
    }

    find(x: number): number {
        if (x === this.root[x]) {
            return x;
        }
        return (this.root[x] = this.find(this.root[x]));
    }

    union(x: number, y: number): void {
        const rootX = this.find(x);
        const rootY = this.find(y);
        if (rootX !== rootY) {
            if (this.rank[x] > this.rank[y]) {
                this.root[rootY] = rootX;
            } else if (this.rank[x] < this.rank[y]) {
                this.root[rootX] = rootY;
            } else {
                this.root[rootY] = rootX;
                this.rank[rootX]++;
            }
        }
    }

    connected(x: number, y: number): boolean {
        return this.find(x) === this.find(y);
    }
}

function validTree(n: number, edges: number[][]): boolean {
    const disjointSet = new DisjointSet(n);
    for (const [x, y] of edges) {
        if (!disjointSet.connected(x, y)) {
            disjointSet.union(x, y);
        } else {
            return false;
        }
    }

    const root = disjointSet.find(0);
    for (let i = 1; i < n; i++) {
        if (root !== disjointSet.find(i)) {
            return false;
        }
    }
    return true;
}
