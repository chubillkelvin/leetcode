function romanToInt(s: string): number {
    const NUMBER = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let newS = s;

    // Handle special cases
    newS = newS.replace("IV", "IIII");
    newS = newS.replace("IX", "VIIII");
    newS = newS.replace("XL", "XXXX");
    newS = newS.replace("XC", "LXXXX");
    newS = newS.replace("CD", "CCCC");
    newS = newS.replace("CM", "DCCCC");

    let result = 0;

    for (const char of newS) {
        result += NUMBER[char];
    }

    return result;
}
