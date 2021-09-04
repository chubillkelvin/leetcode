function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    const arr1 = nums1.length <= nums2.length ? nums1 : nums2; // shorter array
    const arr2 = nums1.length <= nums2.length ? nums2 : nums1; // longer array
    const m = arr1.length;
    const n = arr2.length;

    // Handle edge case - only the shorter array can be empty since m+n >= 1 by constraint
    if (m === 0) return getMedian(arr2);

    const leftArrayLength = Math.ceil((m + n) / 2);
    let min = 0;
    let max = Math.min(arr1.length - 1, leftArrayLength - 1);
    do {
        const curr = Math.floor((max + min) / 2);
        const leftMax1: number = arr1[curr]; // guaranteed to be defined within range max > min
        const leftMax2: number | undefined = leftArrayLength - curr - 2 >= 0 ? arr2[leftArrayLength - curr - 2] : undefined;
        const rightMin1: number | undefined = arr1?.[curr + 1];
        const rightMin2: number = arr2[leftArrayLength - curr - 1]; // guaranteed to be defined within range max > min
        if (leftMax2 !== undefined && rightMin1 !== undefined) {
            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                if ((m + n) % 2 === 0) {
                    return (Math.max(leftMax1, leftMax2) + Math.min(rightMin1, rightMin2)) / 2;
                } else {
                    return Math.max(leftMax1, leftMax2);
                }
            } else {
                if (leftMax1 > rightMin2) {
                    max = curr - 1;
                } else {
                    min = curr + 1;
                }
            }
        } else {
            // All items are taken from arr1 for the left partition
            if (leftMax2 === undefined) {
                if ((m + n) % 2 === 0) {
                    return (leftMax1 + Math.min(rightMin1 ?? Infinity, rightMin2)) / 2;
                } else {
                    return leftMax1;
                }
            }
            // arr1 is exhausted
            if (rightMin1 === undefined) {
                if (leftMax1 <= rightMin2) {
                    if ((m + n) % 2 === 0) {
                        return (Math.max(leftMax1, leftMax2 ?? -Infinity) + Math.min(rightMin1 ?? Infinity, rightMin2)) / 2;
                    } else {
                        return Math.max(leftMax1, leftMax2 ?? -Infinity);
                    }
                } else {
                    if ((m + n) % 2 === 0) {
                        return (arr2[leftArrayLength - 1] + Math.min(leftMax1, arr2[leftArrayLength])) / 2;
                    } else {
                        return arr2[leftArrayLength - 1];
                    }
                }
            }
        }
    } while (max >= min);

    // Edge case when max < min and the searching is finished, all items are taken from arr2
    if ((m + n) % 2 === 0) {
        return (arr2[leftArrayLength - 1] + Math.min(arr1[0] ?? Infinity, arr2[leftArrayLength] ?? Infinity)) / 2;
    } else {
        return arr2[leftArrayLength - 1];
    }
}

function getMedian(nums: number[]): number {
    if (nums.length % 2 === 0) {
        const middleIndex = nums.length / 2;
        return (nums[middleIndex - 1] + nums[middleIndex]) / 2;
    } else {
        return nums[Math.floor(nums.length / 2)];
    }
}
