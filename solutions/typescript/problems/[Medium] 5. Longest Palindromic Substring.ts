function longestPalindrome(s: string): string {
    /**
     * Convert the input from numbers / alphabets only (e.g. "A1B2C3") to the format "A*1*B*2*C*3".
     * The reason is because palindrome can have odd entries (anchored at a character, e.g. "ABA" - B is the anchor);
     * or even entries (anchored in the middle of two characters, e.g. "ABBA" - anchor is between two "B"s).
     */
    const c = s.split("").join("*"); // c stands for converted input of s
    /**
     * 1 <= s.length <= 1000
     * A single character is always a palindrome, thus taking the first char to be the default ans.
     */
    let ans = c[0];
    for (let i = 1; i < c.length; i++) {
        /**
         * For the maximum possible length a palindrome can be found at current index.
         * If this value is smaller than the longest palindrome found so far (ans), then return ans.
         */
        const maxLengthPossible = Math.min(i + 1, c.length - i + 1);
        if (maxLengthPossible <= ans.length) {
            return ans;
        }

        let longestFound = c[i];
        for (let j = 1; j < maxLengthPossible; j++) {
            if (c[i - j] === c[i + j]) {
                longestFound = c.slice(i - j, i + j + 1);
            } else {
                break;
            }
        }
        longestFound = longestFound.replace(/\*/g, ""); // leetcode does not support replaceAll
        if (longestFound.length > ans.length) {
            ans = longestFound;
        }
    }
    return ans;
}
