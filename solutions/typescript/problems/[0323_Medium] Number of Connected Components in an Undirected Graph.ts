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

function countComponents(n: number, edges: number[][]): number {
    const disjointSet = new DisjointSet(n);
    for (const [x, y] of edges) {
        disjointSet.union(x, y);
    }

    const components = new Set();
    for (let i = 0; i < n; i++) {
        components.add(disjointSet.find(i));
    }
    return components.size;
}
