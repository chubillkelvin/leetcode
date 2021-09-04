function isPalindrome(x: number): boolean {
    // Solve without using conversion to string or overflowing the number
    if (x < 0) return false; // negative numbers cannot be palindrome
    if (x < 10) return true; // single digit numbers must be palindrome, including 0
    if (x % 10 === 0) return false; // numbers ending with 0 (except 0 itself) cannot be palindrome
    const maxExponent = Math.floor(Math.log10(x)); // until here, x must be > 10 and x cannot be a multiple of 10
    let number = x;
    for (let i = 0; i <= maxExponent; i++) {
        number -= Math.pow(10, i) * Math.floor((x / Math.pow(10, maxExponent - i)) % 10);
    }
    return number === 0;
}
