function findOrder(numCourses: number, prerequisites: number[][]): number[] {
    const inOrder = new Map<number, Set<number> | null>();

    for (let i = 0; i < numCourses; i++) {
        inOrder.set(i, new Set());
        for (let j = 0; j < prerequisites.length; j++) {
            const [taking, required] = prerequisites[j];
            if (taking === i) {
                inOrder.get(i)!.add(required);
            }
        }
    }

    const taken = [];

    while (taken.length < numCourses) {
        let nextCourse;
        for (const [i, requiredCourses] of inOrder.entries()) {
            if (requiredCourses?.size === 0) {
                nextCourse = i;
                break;
            }
        }

        if (nextCourse === undefined) {
            return [];
        }

        taken.push(nextCourse);
        for (const [_, requiredCourses] of inOrder.entries()) {
            if (requiredCourses?.has(nextCourse)) {
                requiredCourses?.delete(nextCourse);
            }
        }
        inOrder.delete(nextCourse);
    }

    return taken;
}
