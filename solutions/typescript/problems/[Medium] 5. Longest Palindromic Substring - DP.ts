// @ts-ignore
function longestPalindrome(s: string): string {
    /**
     * Dynamic Programming Solution, assume:
     * - isPalindrome(i, j) = true if s.slice(i, j+1) is a palindrome; false when otherwise.
     * Base cases:
     * [1] isPalindrome(i, i) = true (a single character is always a palindrome)
     * [2] isPalindrome(i, i+1) = s[i] === s[i+1]
     */

    // Initialize n*n 2D array with undefined
    const storedAns: boolean[][] = new Array(s.length).fill(undefined).map(() => new Array(s.length).fill(undefined));

    function isPalindrome(start: number, end: number): boolean {
        // Check if the answer has already been computed
        const existingAns = storedAns[start][end];
        if (existingAns) {
            return existingAns;
        }

        // If the ending chars do not match, s.slice(start, end+1) does not form a palindrome
        if (s[start] !== s[end]) {
            storedAns[start][end] = false;
            return false;
        }

        if (start === end || start + 1 === end) {
            // Base case [1] & [2]
            storedAns[start][end] = true;
            return true;
        } else {
            const ans = isPalindrome(start + 1, end - 1);
            storedAns[start][end] = ans;
            return ans;
        }
    }

    let maxLengthFound = 1;
    let maxStart = 0;
    let maxEnd = 0;
    for (let i = 0; i < s.length; i++) {
        // No need to check anymore if max possible length can be found is smaller than existing answer
        if (s.length - 1 - i < maxLengthFound) {
            break;
        }
        for (let j = i + 1; j < s.length; j++) {
            // Skip checking if max possible length can be found is smaller than existing answer
            if (j - i < maxLengthFound) {
                continue;
            }
            if (isPalindrome(i, j)) {
                maxLengthFound = j - i + 1;
                maxStart = i;
                maxEnd = j;
            }
        }
    }
    return s.slice(maxStart, maxEnd + 1);
}
