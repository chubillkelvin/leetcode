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

function smallestStringWithSwaps(s: string, pairs: number[][]): string {
    const disjointSet = new DisjointSet(s.length);

    for (const [x, y] of pairs) {
        disjointSet.union(x, y);
    }

    const sets: string[][] = new Array(s.length);
    for (let i = 0; i < s.length; i++) {
        const curr = sets[disjointSet.find(i)];
        if (Array.isArray(curr)) {
            curr.push(s[i]);
        } else {
            sets[disjointSet.find(i)] = [s[i]];
        }
    }
    sets.map((_) => _.sort().reverse());

    let result = "";
    for (let i = 0; i < s.length; i++) {
        result += sets[disjointSet.find(i)].pop();
    }
    return result;
}
