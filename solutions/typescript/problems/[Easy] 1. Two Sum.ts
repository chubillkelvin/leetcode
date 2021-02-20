function Easy1TwoSum(nums: number[], target: number): number[] {
    const lookup = {};

    for (let i = 0; i < nums.length; i++) {
        const currentNum = nums[i];
        const complementaryNum = target - currentNum;
        if (lookup[complementaryNum] !== undefined) {
            return [lookup[complementaryNum], i];
        }
        lookup[currentNum] = i;
    }

    throw new Error("No solution found");
}
